#include "../inc/ScalarConverter.hpp"
#include <cfloat>
#include <cerrno>
#include <cmath>
#include <limits>

#define PRINT_IMPOSSIBLE "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible"


ScalarConverter::ScalarConverter() {
	std::cout << GREEN << "ScalarConverter Default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << BLUE << "ScalarConverter Copy constructor called" << RESET << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << BLUE << "ScalarConverter Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << RED << "ScalarConverter Destructor called" << RESET << std::endl;
}

static bool isPseudoLiteral(const std::string& s) {
	if (s == "nan")	 { return (true); } 
	if (s == "+inf") { return (true); }
	if (s == "-inf") { return (true); }

	return (false);
}

static bool isPseudoLiteralF(const std::string& s) {
	if (s == "nanf")  { return (true); } 
	if (s == "+inff") { return (true); }
	if (s == "-inff") { return (true); }

	return (false);
}

static bool isInt(const std::string& s) {
	char *end;
	long res = std::strtol(s.c_str(), &end, 10);

	return (*end == '\0' && (res >= INT32_MIN && res <= INT32_MAX));
}

static bool isDouble(const std::string& s) {
	char *end; errno = 0;
	std::strtod(s.c_str(), &end);

	return (*end == '\0' && errno != ERANGE);
}

static bool isFloat(const std::string& s) {
	char *end; errno = 0;
	double res = std::strtod(s.c_str(), &end);

	return (*end == 'f' && *(end + 1) == '\0')
		&& (errno != ERANGE && res >= FLT_MIN && res <= FLT_MAX);
}

static bool isChar(const std::string& s) {
	return (s.length() == 1 && std::isprint(s[0]));
}

ScalarConverter::LiteralType ScalarConverter::getType(const std::string& s) {
	if (!s.empty()) {
		if (isPseudoLiteral(s)) {
			std::cout << "literal" << std::endl;
			return SC_PSEUDO;
		}
		if (isPseudoLiteralF(s)) {
			std::cout << "literalF" << std::endl;
			return SC_PSEUDOF;
		}
		if (isInt(s)) {
			std::cout << "int" << std::endl;
			return SC_INT;
		}
		if (isDouble(s)) {
			std::cout << "double" << std::endl;
			return SC_DOUBLE;
		}
		if (isFloat(s)) {
			std::cout << "float" << std::endl;
			return SC_FLOAT;
		}
		if (isChar(s)) {
			std::cout << "char" << std::endl;
			return SC_CHAR;
		}
	}
	std::cout << "WRONG" << std::endl;
	return SC_INVALID;
}


static void printCharStatement(char c) {
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
}


static void printFloatStatement(float f) {
	std::cout << f;
	if (f == std::floor(f)) {
		std::cout << ".0f";
	} else {
		std::cout << "f";
	}
}


static void printDoubleStatement(double d) {
	std::cout << d;
	if (d == std::floor(d)) {
		std::cout << ".0";
	}
}

static bool isInLimitChar(double c) {
	if (c < std::numeric_limits<char>::min() || c > std::numeric_limits<char>::max())
		return (false);
	return (true);
}

static bool isInLimitInt(double i) {
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static void printFromChar(char c) {
	std::cout << "char: "; printCharStatement(c); std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: "; printFloatStatement(static_cast<float>(c));		std::cout << std::endl;
	std::cout << "double: "; printDoubleStatement(static_cast<double>(c));	std::cout << std::endl;
}

static void printFromInt(int i) {
	std::cout << "char: ";
	if (!isInLimitChar(i))
		std::cout << "impossible";
	else
		printCharStatement(static_cast<char>(i));
	std::cout << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: ";	printFloatStatement(static_cast<float>(i));		std::cout << std::endl;
	std::cout << "double: "; printDoubleStatement(static_cast<double>(i));	std::cout << std::endl;
}

static void printFromFloat(float f) {
	std::cout << "char: ";
	if (!isInLimitChar(f)) std::cout << "impossible";
	else printCharStatement(static_cast<char>(f));
	std::cout << std::endl;

	std::cout << "int: ";
	if (!isInLimitInt(f)) std::cout << "impossible";
	else std::cout << static_cast<int>(f);
	std::cout << std::endl;

	std::cout << "float: ";  printFloatStatement(f);  std::cout << std::endl;
	std::cout << "double: "; printDoubleStatement(f); std::cout << std::endl;


}


static void printFromDouble(double d) {
	std::cout << "char: ";
	if (!isInLimitChar(d)) std::cout << "impossible";
	else printCharStatement(static_cast<char>(d));
	std::cout << std::endl;

	std::cout << "int: ";
	if (!isInLimitInt(d)) std::cout << "impossible";
	else std::cout << static_cast<int>(d);
	std::cout << std::endl;

	std::cout << "float: ";  printFloatStatement(d);  std::cout << std::endl;
	std::cout << "double: "; printDoubleStatement(d); std::cout << std::endl;
}



static void printFromPseudo(const std::string& literal) {
	(void)literal;

}

static void printFromPseudoF(const std::string& literal) {
	(void)literal;

}

void ScalarConverter::convert(const std::string& literal)
{
	switch (getType(literal))
	{
		case SC_CHAR:	{ printFromChar(literal[0]); 							break; }
		case SC_INT:	{ printFromInt(std::atoi(literal.c_str()));				break; }
		case SC_DOUBLE:	{ printFromDouble(std::strtod(literal.c_str(), NULL));	break; }
		case SC_FLOAT:	{ printFromFloat(std::strtof(literal.c_str(), NULL));	break; }
		case SC_PSEUDO:	{ printFromPseudo(literal);								break; }
		case SC_PSEUDOF:{ printFromPseudoF(literal);							break; }
		default: {
            std::cout << PRINT_IMPOSSIBLE << std::endl;
			break;
		}
	}
}



