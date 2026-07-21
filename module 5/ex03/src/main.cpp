#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;
	Bureaucrat boss("Zaphod", 1);

	std::cout << "===== Valid form names =====" << std::endl;

	std::cout << "\n-- creating shrubbery creation --" << std::endl;
	AForm* f1 = intern.makeForm("shrubbery creation", "garden");
	if (f1) {
		boss.signForm(*f1);
		boss.executeForm(*f1);
	}

	std::cout << "\n-- creating robotomy request --" << std::endl;
	AForm* f2 = intern.makeForm("robotomy request", "Bender");
	if (f2) {
		boss.signForm(*f2);
		boss.executeForm(*f2);
	}

	std::cout << "\n-- creating presidential pardon --" << std::endl;
	AForm* f3 = intern.makeForm("presidential pardon", "Arthur Dent");
	if (f3) {
		boss.signForm(*f3);
		boss.executeForm(*f3);
	}

	std::cout << "\n===== Invalid form name =====" << std::endl;
	AForm* f4 = intern.makeForm("time travel request", "Marty McFly");
	if (f4 == NULL)
		std::cout << "(correctly received NULL, as expected)" << std::endl;

	std::cout << "\n===== Cleanup =====" << std::endl;
	delete f1;
	delete f2;
	delete f3;

	return 0;
}