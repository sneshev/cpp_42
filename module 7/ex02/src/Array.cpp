#include "../inc/Array.hpp"

Array::Array() {
	std::cout << GREEN << "Array Default constructor called" << RESET << std::endl;
}

Array::Array(const Array& other) {
	std::cout << BLUE << "Array Copy constructor called" << RESET << std::endl;
	*this = other;
}

Array& Array::operator=(const Array& other) {
	std::cout << BLUE << "Array Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

Array::~Array() {
	std::cout << RED << "Array Destructor called" << RESET << std::endl;
}
