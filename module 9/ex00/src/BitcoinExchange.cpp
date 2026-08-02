#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: _db()
{
	std::cout << GREEN << "BitcoinExchange Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const char* dbName)
	: _db()
{
	loadDatabase(dbName);
	std::cout << BLUE << "BitcoinExchange constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	std::cout << BLUE << "BitcoinExchange Copy constructor called" << RESET << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << BLUE << "BitcoinExchange Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_db = other._db;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED << "BitcoinExchange Destructor called" << RESET << std::endl;
}

static int giveError(const char *s, int errorCode) {
	std::cout << "Error: " << s  << "." << std::endl;
	return (errorCode);
}

static int giveError(const char *s) {
	return (giveError(s, 1));
}

static bool isValidDate(long year, long month, long day) {
	if (year < STARTYEAR || year > ENDYEAR)
		return (false);

	if (month < 1 || month > 12)
		return (false);

	const int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int lastDayOfMonth = monthDays[month];
	if (month == 2) {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			lastDayOfMonth = 29;
		}
	}
	
	if (day < 1 || day > lastDayOfMonth)
		return (false);
	
	return (true);
}

static bool db_isValidLine(const std::string& s) {
	std::istringstream iss(s);
	int year, month, day;
	char c1, c2, c3;
	float rate;

	if (!(iss >> year >> c1 >> month >> c2 >> day >> c3 >> rate))
		return (false);
	if (c1 != '-' || c2 != '-' || c3 != ',')
		return (false);
	if (!iss.eof())
		return (false);
	if (rate < 0)
		return (false);

	return (isValidDate(year, month, day));
}

static void db_addLine(const std::string& s, std::map<std::string, float>& m) {
	std::istringstream ss(s);
	std::string date;
	float rate;

	std::getline(ss, date, ',');
	ss >> rate;

	m[date] = rate;
}

void BitcoinExchange::printDB() {
	for (std::map<std::string, float>::iterator it = _db.begin(); it != _db.end(); ++it) {
		std::cout << it->first << " is => " << it->second << std::endl;
	}
}

void BitcoinExchange::loadDatabase(const char* dbFileName) {
	std::ifstream dbFile(dbFileName);
	if (!dbFile.is_open())
		exit(giveError(ERR_BADFILE));

	std::string line;
	std::getline(dbFile, line);
	if (line != "date,exchange_rate") {
		if (db_isValidLine(line)) {
			db_addLine(line, _db);
		}
	}

	while (std::getline(dbFile, line)) {
		if (db_isValidLine(line)) {
			db_addLine(line, _db);
		}
	}

	if (_db.empty())
		exit(giveError(ERR_DBEMPTY));
}

static void validateLine(const std::string& s, std::string& inDate, float& inAmount) {
	std::istringstream iss(s);
	int year, month, day;
	char c1, c2, c3;
	float amount;

	if (!(iss >> year >> c1 >> month >> c2 >> day >> c3 >> amount ))
		throw std::runtime_error(std::string("bad input: " + s));
	if (c1 != '-' || c2 != '-' || c3 != '|')
		throw std::runtime_error(std::string("bad input: " + s));
	if (!iss.eof())
		throw std::runtime_error(std::string("bad input: " + s));
	if (!isValidDate(year, month, day))
		throw std::runtime_error(std::string("bad input: " + s));
	if (amount < 0)
		throw std::runtime_error(std::string("not a positive number"));
	if (amount > 1000)
		throw std::runtime_error(std::string("too large a number"));

	inAmount = amount;

	std::istringstream iss2(s);
	std::getline(iss2, inDate, '|');
}

float BitcoinExchange::calculatePrice(std::string& date, float amount) {
	std::map<std::string, float>::iterator it = _db.upper_bound(date);
	if (it == _db.begin())
		throw std::runtime_error("date too early");

	it--;

	return (amount * it->second);
}

void BitcoinExchange::checkPrice(const std::string& s) {
	std::string date;
	float amount;

	try {
		validateLine(s, date, amount);
		std::cout << date << "=> " << amount << " = " << calculatePrice(date, amount) << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << "." << std::endl;
	}
}

