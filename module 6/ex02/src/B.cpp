#include "../inc/B.hpp"

B::B() {
	std::cout << GREEN << "B Default constructor called" << RESET << std::endl;
}

B::B(const B& other) {
	std::cout << BLUE << "B Copy constructor called" << RESET << std::endl;
	*this = other;
}

B& B::operator=(const B& other) {
	std::cout << BLUE << "B Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

B::~B() {
	std::cout << RED << "B Destructor called" << RESET << std::endl;
}
