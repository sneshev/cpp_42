#include "Fixed.hpp"

const int Fixed::_fractionalBitAmount = 8;

Fixed::Fixed() : _value(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;

	_value = other.getRawBits();
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}
