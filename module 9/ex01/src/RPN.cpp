#include "../inc/RPN.hpp"

RPN::RPN() {
	std::cout << GREEN << "RPN Default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN& other) {
	std::cout << BLUE << "RPN Copy constructor called" << RESET << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	std::cout << BLUE << "RPN Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_s = other._s;
	}
	return (*this);
}

RPN::~RPN() {
	std::cout << RED << "RPN Destructor called" << RESET << std::endl;
}


static bool	isSign(char c) {
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false); 
}

static bool isNum(char c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void RPN::evaluate(char sign) {
	if (_s.size() < 2)
		throw std::runtime_error("bad input");

	int b = _s.top(); _s.pop();
	int a = _s.top(); _s.pop();

	switch (sign)
	{
		case '+': _s.push(a + b); break;
		case '-': _s.push(a - b); break;
		case '*': _s.push(a * b); break;
		case '/':
			if (b == 0) { throw std::runtime_error("bad input"); }
			_s.push(a / b); break;
	}
}

void RPN::takeElement(char c) {
	if (isNum(c)) {
		_s.push(c - '0');
	}
	else if (isSign(c)) {
		evaluate(c);
	} 
	else {
		throw std::runtime_error("bad input");
	}
}

int RPN::getResult() {
	if (_s.size() == 1) {
		return (_s.top());
	}
	throw std::runtime_error("bad input");
}