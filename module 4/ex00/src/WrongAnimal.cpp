#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << GREEN << "WrongAnimal Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string inType) : _type(inType){
	std::cout << GREEN << "WrongAnimal Default constructor called" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << BLUE << "WrongAnimal Copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << BLUE << "WrongAnimal Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return (_type);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal: *WrongAnimal sounds*" << std::endl;
}
