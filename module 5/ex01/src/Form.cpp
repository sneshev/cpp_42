#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(const std::string& inName, int inGradeToSign, int inGradeToExecute) 
	: _name(inName), _gradeToSign(inGradeToSign), _gradeToExecute(inGradeToExecute), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	if (_gradeToSign > 150 || _gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
	std::cout << GREEN << "Form Default constructor called" << RESET << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_isSigned(other._isSigned)
{
	std::cout << BLUE << "Form Copy constructor called" << RESET << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << BLUE << "Form Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {
	std::cout << RED << "Form Destructor called" << RESET << std::endl;
}


const std::string& Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

bool Form::getSignedStatus() const {
	return _isSigned;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign) {
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& s, const Form& f) {
	s << "Form \"" << f.getName() << "\"" << std::endl;
	s << "signed = " << f.getSignedStatus() << std::endl;
	s << "grade to sign = " << f.getGradeToSign() << std::endl;
	// s << "grade to execute = " << f.getGradeToExecute() << std::endl;
	return s;
}
