#include "../inc/Dog.hpp"


Dog::Dog()
	: Animal("Dog"),
	_brain(new Brain)
{
	std::cout << GREEN << "Dog Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Dog() {
	std::cout << BLUE << "Dog Copy constructor called" << RESET << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << BLUE << "Dog Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << _type << ": bark" << std::endl;
}