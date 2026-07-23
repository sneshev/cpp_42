#include "../inc/A.hpp"

A::A() {
	std::cout << GREEN << "A Default constructor called" << RESET << std::endl;
}

A::A(const A& other) {
	std::cout << BLUE << "A Copy constructor called" << RESET << std::endl;
	*this = other;
}

A& A::operator=(const A& other) {
	std::cout << BLUE << "A Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

A::~A() {
	std::cout << RED << "A Destructor called" << RESET << std::endl;
}
