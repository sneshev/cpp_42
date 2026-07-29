#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <string>

#define STARTYEAR 2009
#define ENDYEAR 2026
#define BADFILE "could not open file"

int giveError(const char *s, int errorCode) {
	std::cout << "Error: " << s  << "." << std::endl;
	return (errorCode);
}

int giveError(const char *s) {
	return (giveError(s, 1));
}

std::ifstream openFile(int argc, char* argv[]) {
	if (argc != 2)
		exit(giveError(BADFILE));

	std::ifstream file(argv[1]);
	if (!file.is_open())
		exit(giveError(BADFILE));

	return (file);
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

static bool isValidDate(const std::string& s) {
	int year, month, day;
	char c1, c2;

	std::istringstream iss(s);
	if (!(iss >> year >> c1 >> month >> c2 >> day))
		return (false);
	if (c1 != '-' || c2 != '-')
		return (false);
	if (!iss.eof())
		return (false);

	return (isValidDate(year, month, day));
}


void loadDatabase(std::ifstream& file, std::map<std::string, float>& db) {
	(void)db;
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		
	}

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string valueString;

		std::getline(ss, date, ',');
		std::getline(ss, valueString);

		
		if (!isValidDate(date)) {
			std::cout << "L" << std::endl;
		}
	}
}

int main(int argc, char* argv[]) {
	std::ifstream file = openFile(argc, argv);

	std::map<std::string, float> db;
	loadDatabase(file, db);

	return (0);
}


/*
#include <string>
#include <sstream>

static bool isValidDate(int year, int month, int day)
{
    if (year < STARTYEAR || year > ENDYEAR)
        return false;
    if (month < 1 || month > 12)
        return false;

    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && isLeap)
        maxDay = 29;

    return day >= 1 && day <= maxDay;
}

static bool isValidDate(const std::string& s)
{
    std::istringstream iss(s);
    int year, month, day;
    char dash1, dash2;

    if (!(iss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (!iss.eof())
        return false; // trailing junk after the day

    return isValidDate(year, month, day);
}
*/