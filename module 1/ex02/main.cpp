#include <iostream>



int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::endl;

	std::cout << "& of string    : " << &string		<< std::endl;
	std::cout << "& of stringPTR : " << stringPTR	<< std::endl;
	std::cout << "& of stringREF : " << &stringREF	<< std::endl;

	std::cout << std::endl;

	std::cout << "string    = " << string		<< std::endl;
	std::cout << "stringPTR = " << *stringPTR	<< std::endl;
	std::cout << "stringREF = " << stringREF	<< std::endl;

	std::cout << std::endl;
}