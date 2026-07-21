#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(const std::string& inName, int inGradeToSign, int inGradeToExecute) 
	: _name(inName), _gradeToSign(inGradeToSign), _gradeToExecute(inGradeToExecute), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	if (_gradeToSign > 150 || _gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
	std::cout << GREEN << "AForm Default constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_isSigned(other._isSigned)
{
	std::cout << BLUE << "AForm Copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << BLUE << "AForm Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {
	std::cout << RED << "AForm Destructor called" << RESET << std::endl;
}

void AForm::execute(const Bureaucrat& b) const {
	if (!_isSigned) {
		throw AForm::FormNotSignedException();
	} else if (b.getGrade() > _gradeToExecute) {
		throw AForm::GradeTooLowException();
	} else {
		doAction();
	}
}


const std::string& AForm::getName() const {
	return _name;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

bool AForm::getSignedStatus() const {
	return _isSigned;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (_isSigned) {
		throw AForm::FormAlreadySignedException();
	} else if (b.getGrade() > _gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return ("Form already signed");
}

std::ostream& operator<<(std::ostream& s, const AForm& f) {
	s << "AForm \"" << f.getName() << "\"" << std::endl;
	s << "signed = " << f.getSignedStatus() << std::endl;
	s << "grade to sign = " << f.getGradeToSign() << std::endl;
	s << "grade to execute = " << f.getGradeToExecute() << std::endl;
	return s;
}
