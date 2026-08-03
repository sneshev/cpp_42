#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << GREEN << "PmergeMe Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	std::cout << BLUE << "PmergeMe Copy constructor called" << RESET << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	std::cout << BLUE << "PmergeMe Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

PmergeMe::~PmergeMe() {
	std::cout << RED << "PmergeMe Destructor called" << RESET << std::endl;
}
