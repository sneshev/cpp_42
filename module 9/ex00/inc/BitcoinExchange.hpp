#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <map>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#define STARTYEAR 2009
#define ENDYEAR 2026

#define ERR_DBEMPTY "empty database"
#define ERR_BADFILE "could not open file"
#define ERR_NEGATIVENUM "nu"

class BitcoinExchange {
	private:
		std::map<std::string, float> _db;

		void loadDatabase(const char* dbFileName);

	public:
		BitcoinExchange();
		BitcoinExchange(const char* dbName);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void printDB();
		
};
