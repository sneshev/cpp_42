#include "../inc/Cat.hpp"


Cat::Cat()
	: Animal("Cat"),
	_brain(new Brain)
{
	std::cout << GREEN << "Cat Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal() {
	std::cout << BLUE << "Cat Copy constructor called" << RESET << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << BLUE << "Cat Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << _type << ": meow meow" << std::endl;
}