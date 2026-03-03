#include "../inc/Dog.hpp"


Dog::Dog()
	: Animal("Dog"),
	_brain(new Brain)
{
	std::cout << GREEN << "Dog Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other),
	_brain(new Brain(*other._brain))
{
	std::cout << BLUE << "Dog Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << BLUE << "Dog Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
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

int Dog::setIdea(unsigned int index, const std::string inIdea) {
	return (_brain->setIdea(index, inIdea));
}

std::string Dog::getIdea(unsigned int index) {
	return (_brain->getIdea(index));
}