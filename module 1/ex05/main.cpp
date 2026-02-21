#include "Harl.hpp"
int main()
{
	Harl harl;

	std::cout << "DEBUG" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\nINFO" << std::endl;
	harl.complain("INFO");

	std::cout << "\nERROR" << std::endl;
	harl.complain("ERROR");
	
	std::cout << "\nWARNING" << std::endl;
	harl.complain("WARNING");
}