#include "../inc/AForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& inTarget)
	: AForm("RobotomyRequestForm", 72, 45), _target(inTarget)
{
	std::cout << GREEN << "RobotomyRequestForm Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << RESET << std::endl;
}


void RobotomyRequestForm::doAction() const {
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	std::cout << "*drilling noises*\n";
	if (std::rand() % 2) {
		std::cout << _target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << _target << " robotomy failed" << std::endl;
	}
}
