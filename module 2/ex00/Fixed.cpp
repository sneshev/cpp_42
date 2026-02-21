#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _fixed(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;

	_fixed = other.getRawBits();
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_fixed = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed);
}

void Fixed::setRawBits(int const raw) {
	_fixed = raw;
}
