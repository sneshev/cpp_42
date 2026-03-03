#include "../inc/Cat.hpp"


Cat::Cat()
	: Animal("Cat"),
	_brain(new Brain)
{
	std::cout << GREEN << "Cat Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other),
	_brain(new Brain(*other._brain))
{
	std::cout << BLUE << "Cat Copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << BLUE << "Cat Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
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

int Cat::setIdea(unsigned int index, const std::string inIdea) {
	return (_brain->setIdea(index, inIdea));
}

std::string Cat::getIdea(unsigned int index) {
	return (_brain->getIdea(index));
}