#include "../inc/Span.hpp"

Span::Span()
	: _numbers(), _maxSize(0)
{
	std::cout << GREEN << "Span Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N)
	: _numbers(), _maxSize(N) 
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
		_maxSize = other._maxSize;
	}
	return (*this);
}

Span::~Span() {
	std::cout << RED << "Span Destructor called" << RESET << std::endl;
}

void Span::addNumber(int nb) {
	if (_numbers.size() == _maxSize) {
		throw (ContainerFullException());
	}
	_numbers.insert(nb);
}

size_t Span::shortestSpan() {
	if (_numbers.size() < 2) { throw std::invalid_argument("Need at least 2 elements to compute a gap"); }

	std::multiset<int>::iterator it = _numbers.begin();
	std::multiset<int>::iterator next = it;
	++next;
	size_t smallest = *(next++) - *(it++);

	for (; next != _numbers.end(); ++it, ++next) {
		size_t diff = *next - *it;
		if (diff < smallest)
			smallest = diff;
	}
	return (smallest);
}


size_t Span::longestSpan() {
	if (_numbers.size() < 2) { throw std::invalid_argument("Need at least 2 elements to compute a gap"); }

	long start = *_numbers.begin();
	long end = *_numbers.rbegin();
	return (static_cast<size_t>(end - start));
}

const char* Span::ContainerFullException::what() const noexcept {
	return "Container is full";
}

