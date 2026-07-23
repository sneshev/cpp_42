#include "../inc/Base.hpp"

Base::Base() {
	std::cout << GREEN << "Base Default constructor called" << RESET << std::endl;
}

Base::Base(const Base& other) {
	std::cout << BLUE << "Base Copy constructor called" << RESET << std::endl;
	*this = other;
}

Base& Base::operator=(const Base& other) {
	std::cout << BLUE << "Base Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

Base::~Base() {
	std::cout << RED << "Base Destructor called" << RESET << std::endl;
}
