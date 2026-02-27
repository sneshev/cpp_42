#include "../inc/Animal.hpp"

Animal::Animal() {
	std::cout << GREEN << "Animal Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << BLUE << "Animal Copy constructor called" << RESET << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << BLUE << "Animal Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

std::string Animal::getType() {
	return (_type);
}

void Animal::makeSound() {
	std::cout << _type << ": *Animal sounds*" << std::endl;
}


