#include "../inc/Intern.hpp"

Intern::Intern() {
	std::cout << GREEN << "Intern Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << BLUE << "Intern Copy constructor called" << RESET << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << BLUE << "Intern Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

Intern::~Intern() {
	std::cout << RED << "Intern Destructor called" << RESET << std::endl;
}

AForm* Intern::makeForm(const std::string& inName, const std::string& inTarget) {
	for (int i = 0; i < 3; i++) {
		if (inName == forms[i]) {
			std::cout << "Intern creates " << inName << std::endl;
			return formCreators[i](inTarget);
		}
	}
	std::cout << "Form " << inName << " not found." << std::endl;
	return (NULL);
}