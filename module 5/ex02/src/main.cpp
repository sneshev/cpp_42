#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	std::cout << "===== ShrubberyCreationForm =====" << std::endl;
	{
		try {
			Bureaucrat highGrade("Alice", 1);
			Bureaucrat lowGrade("Bob", 150);
			ShrubberyCreationForm shrub("garden");

			std::cout << shrub << std::endl;

			std::cout << "\n-- low grade tries to sign (should fail) --" << std::endl;
			lowGrade.signForm(shrub);

			std::cout << "\n-- high grade signs (should succeed) --" << std::endl;
			highGrade.signForm(shrub);

			std::cout << "\n-- low grade tries to execute signed form (should fail, grade too low) --" << std::endl;
			lowGrade.executeForm(shrub);

			std::cout << "\n-- high grade executes signed form (should succeed, writes garden_shrubbery) --" << std::endl;
			highGrade.executeForm(shrub);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}


	std::cout << "\n===== RobotomyRequestForm =====" << std::endl;
	{
		try {
			Bureaucrat boss("Zorg", 1);
			RobotomyRequestForm robotomy("Bender");

			std::cout << "\n-- executing before signing (should fail, not signed) --" << std::endl;
			boss.executeForm(robotomy);

			std::cout << "\n-- signing --" << std::endl;
			boss.signForm(robotomy);

			std::cout << "\n-- executing several times to see random success/fail --" << std::endl;
			for (int i = 0; i < 5; i++) {
				boss.executeForm(robotomy);
				std::cout << std::endl;
			}
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
	}

	std::cout << "\n===== PresidentialPardonForm =====" << std::endl;
	{
		try {
			Bureaucrat president("Zaphod", 1);
			Bureaucrat clerk("Ford", 50);
			PresidentialPardonForm pardon("Arthur Dent");

			std::cout << "\n-- clerk tries to sign (grade 50, needs 25, should fail) --" << std::endl;
			clerk.signForm(pardon);

			std::cout << "\n-- president signs (should succeed) --" << std::endl;
			president.signForm(pardon);

			std::cout << "\n-- clerk tries to execute (grade 50, needs 5, should fail) --" << std::endl;
			clerk.executeForm(pardon);

			std::cout << "\n-- president executes (should succeed) --" << std::endl;
			president.executeForm(pardon);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << "\n===== Constructing forms with invalid grades =====" << std::endl;
	{
		try {
			// This should never actually throw since grades are hardcoded correctly,
			// but this block confirms your base AForm constructor validation still works.
			Bureaucrat b("Test", 1);
			AForm* forms[3] = {
				new ShrubberyCreationForm("test1"),
				new RobotomyRequestForm("test2"),
				new PresidentialPardonForm("test3")
			};

			std::cout << "\n-- polymorphism check: executing via AForm* base pointers --" << std::endl;
			for (int i = 0; i < 3; i++) {
				b.signForm(*forms[i]);
				b.executeForm(*forms[i]);
				std::cout << std::endl;
			}

			std::cout << "\n-- deleting via base pointer (checks virtual destructor) --" << std::endl;
			for (int i = 0; i < 3; i++)
				delete forms[i];
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}