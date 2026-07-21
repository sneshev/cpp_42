#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("target")
{
	std::cout << GREEN << "ShrubberyCreationForm Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& inTarget)
	: AForm("ShrubberyCreationForm", 145, 137), _target(inTarget)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << BLUE << "ShrubberyCreationForm Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_target = other._target;
	}
	return (*this);

}

void ShrubberyCreationForm::doAction() const {
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open()) {
		throw std::runtime_error("could not create file");
	}
	file << "     &&&&\n    &&&&&\n   &&&&&&\n     ||\n     ||\n";
	file.close();
}

AForm* ShrubberyCreationForm::create(const std::string& target) {
	return new ShrubberyCreationForm(target);
}