#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
	std::cout << "--- Valid Form ---" << std::endl;
	try {
		Form f("Tax Form", 50, 100);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Form with sign grade too high (0) ---" << std::endl;
	try {
		Form f("Broken Form", 0, 100);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Form with exec grade too low (200) ---" << std::endl;
	try {
		Form f("Broken Form", 50, 200);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Bureaucrat signs successfully (grade high enough) ---" << std::endl;
	try {
		Bureaucrat b("Alice", 10);
		Form f("Tax Form", 50, 100);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Bureaucrat fails to sign (grade too low) ---" << std::endl;
	try {
		Bureaucrat b("Bob", 100);
		Form f("Tax Form", 50, 100);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Sign at exact boundary grade (should succeed) ---" << std::endl;
	try {
		Bureaucrat b("Carol", 50);
		Form f("Tax Form", 50, 100);
		b.signForm(f);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}