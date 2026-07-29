#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << GREEN << "BitcoinExchange Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	std::cout << BLUE << "BitcoinExchange Copy constructor called" << RESET << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << BLUE << "BitcoinExchange Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED << "BitcoinExchange Destructor called" << RESET << std::endl;
}
