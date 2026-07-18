#include "../inc/Bureaucrat.hpp"


/*
	Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
	either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
*/

Bureaucrat::Bureaucrat(const std::string& inName, int inGrade)
	: _name(inName) {
	if (inGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (inGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = inGrade;
	std::cout << GREEN << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
	: _name(other._name), _grade(other._grade)
{
	std::cout << BLUE << "Bureaucrat Copy constructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << BLUE << "Bureaucrat Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat Destructor called" << RESET << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

//goes down
void Bureaucrat::incrementGrade() {
	if (_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

//goes up
void Bureaucrat::decrementGrade() {
	if (_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b) {
	s << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return s;
}
