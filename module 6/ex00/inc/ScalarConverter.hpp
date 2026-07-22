#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		enum LiteralType {
			SC_CHAR,
			SC_INT,
			SC_FLOAT,
			SC_DOUBLE,
			SC_PSEUDO,
			SC_INVALID
		};

		static LiteralType getType(const std::string& s);

	public:
		static void convert(const std::string& literal);
};

/*
	'a'
	42 (-42)
	42.0 (-42.0)
	42.0f (-42.0f)
	nan
	nanf
	+inf (-inf)
	+inff (-inff)
*/