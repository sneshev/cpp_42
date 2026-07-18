#include "../inc/Bureaucrat.hpp"

#include "../inc/Bureaucrat.hpp"

int main() {
	{
		std::cout << "--- Valid Bureaucrat ---" << std::endl;
		{
			try {
				Bureaucrat b("Alice", 50);
				std::cout << b;
			}
			catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}

	{
		std::cout << "\n--- Grade too high (0) ---" << std::endl;
		{
			try {
				Bureaucrat b("Bob", 0);
				std::cout << b;
			}
			catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}

	{
		std::cout << "\n--- Grade too low (200) ---" << std::endl;
		{
			try {
				Bureaucrat b("Carol", 200);
				std::cout << b;
			}
			catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}

	{
		std::cout << "\n--- incrementGrade at limit (grade 1) ---" << std::endl;
		{
			Bureaucrat b("Dave", 1);
			try {
				std::cout << b;
				b.incrementGrade();
				std::cout << b;
			}
			catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}

	{
		std::cout << "\n--- decrementGrade at limit (grade 150) ---" << std::endl;
		{
			Bureaucrat b("Eve", 150);
			try {
				std::cout << b;
				b.decrementGrade();
				std::cout << b;
			}
			catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}

	{
		std::cout << "\n--- increment/decrement normal use ---" << std::endl;
		{
			Bureaucrat b("Frank", 75);
			try {
				std::cout << b;
				b.incrementGrade();
				std::cout << b;
				b.decrementGrade();
				std::cout << b;
			}
			catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}

	return 0;
}
