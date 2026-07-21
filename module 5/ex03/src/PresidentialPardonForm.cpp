#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& inTarget)
	: AForm("PresidentialPardonForm", 25, 5), _target(inTarget)
{
	std::cout << GREEN << "PresidentialPardonForm Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::doAction() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
