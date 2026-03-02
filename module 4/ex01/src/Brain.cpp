#include "../inc/Brain.hpp"
Brain::Brain() {
	std::cout << GREEN << "Brain Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << BLUE << "Brain Copy constructor called" << RESET << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << BLUE << "Brain Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		for (int i = 0; i < MAXTHOUGHTS; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << RED << "Brain Destructor called" << RESET << std::endl;
}