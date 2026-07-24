#include "../inc/Span.hpp"

Span::Span()
	: _numbers(), _size(0)
{
	std::cout << GREEN << "Span Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N)
	: _numbers(), _size(N) 
{
	std::cout << GREEN << "Span constructor called" << RESET << std::endl;
}

Span::Span(const Span& other) {
	std::cout << BLUE << "Span Copy constructor called" << RESET << std::endl;
	*this = other;
}

Span& Span::operator=(const Span& other) {
	std::cout << BLUE << "Span Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_numbers = other._numbers;
		_size = other._size;
	}
	return (*this);
}

Span::~Span() {
	std::cout << RED << "Span Destructor called" << RESET << std::endl;
}

void Span::addNumber(int nb) {
	if (_numbers.size() == _size) {
		throw (ContainerFullException());
	}
	_numbers.insert(nb);
}

size_t Span::shortestSpan() {
	size_t diff = 0;

	for (std::multiset<int>::iterator it = _numbers.begin(); it != _numbers.end(); it++) {
		it++; 
		/*
		
		YOU LEFT IT HERE MOFO...
		
		
		
		*/
	}
}


size_t Span::longestSpan() {

}

const char* Span::ContainerFullException::what() const noexcept {
	return "Container is full";
}