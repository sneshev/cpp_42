#include "../inc/C.hpp"

C::C() {
	std::cout << GREEN << "C Default constructor called" << RESET << std::endl;
}

C::C(const C& other) {
	std::cout << BLUE << "C Copy constructor called" << RESET << std::endl;
	*this = other;
}

C& C::operator=(const C& other) {
	std::cout << BLUE << "C Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

C::~C() {
	std::cout << RED << "C Destructor called" << RESET << std::endl;
}
