#include "Fixed.hpp"

const int Fixed::_fractionalBitAmount = 8;


		/*		CONSTRUCTORS AND DESTRUCTORS	*/
Fixed::Fixed() : _value(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;

	_value = other.getRawBits();
}

Fixed::Fixed(int const i) {
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	_value = i << _fractionalBitAmount;
}

Fixed::Fixed(float const fl) {
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	_value = roundf(fl * (1 << _fractionalBitAmount));
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

		/*		OPERATORS			*/
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}


		/*		GETTER / SETTERS	*/
int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

		/*		OTHER FUNCTIONS		*/
int Fixed::toInt(void) const {
	return (_value >> _fractionalBitAmount);
}

float Fixed::toFloat() const {
	return (((float)_value / (1 << _fractionalBitAmount)));
}