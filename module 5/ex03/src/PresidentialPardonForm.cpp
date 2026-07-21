#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout << GREEN << "PresidentialPardonForm Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& inTarget)
	: AForm("PresidentialPardonForm", 25, 5), _target(inTarget)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << BLUE << "PresidentialPardonForm Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_target = other._target;
	}
	return (*this);

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::doAction() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::create(const std::string& target) {
	return new PresidentialPardonForm(target);
}
