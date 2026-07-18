#include "../inc/Bureaucrat.hpp"


/*
	Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
	either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
*/

Bureaucrat::Bureaucrat(int inGrade) {
	if (inGrade < 0 || inGrade > 150)
		;
	_grade = inGrade;
	std::cout << GREEN << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << BLUE << "Bureaucrat Copy constructor called" << RESET << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << BLUE << "Bureaucrat Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat Destructor called" << RESET << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

const int Bureaucrat::getGrade() const {
	return _grade;
}

//goes down
void Bureaucrat::incrementGrade() {
	if (_grade == 0) {

	}
	_grade--;
}

//goes up
void Bureaucrat::decrementGrade() {
	if (_grade == 150) {

	}
	_grade++;
}

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b) {
	s << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return s;
}
