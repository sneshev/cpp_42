#include "../inc/WrongCat.hpp"


WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	std::cout << BLUE << "WrongCat Copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << BLUE << "WrongCat Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;

}

void WrongCat::makeSound() const {
	std::cout << _type << ": meow meow" << std::endl;
}