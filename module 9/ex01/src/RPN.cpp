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
		_expecting = other._expecting;
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
	if (_expecting == NUM1 && isNum(c)) {
		_s.push(c - '0');
		_expecting = NUM2;
	}
	else if (_expecting == NUM2 && isNum(c)) {
		_s.push(c - '0');
		_expecting = SIGN;
	} 
	else if (_expecting == SIGN && isSign(c)) {
		evaluate(c);
		_expecting = NUM2;
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