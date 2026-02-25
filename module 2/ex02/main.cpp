#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a( Fixed(2) + Fixed(3));
	std::cout << a << std::endl;
	return 0;
}