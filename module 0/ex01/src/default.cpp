#include "../includes/default.hpp"

void print(str message) {
	std::cout << message;
}

void print(int nb) {
	std::cout << nb;
}

void print(char c) {
	std::cout << c;
}

void printnl(str message) {
	print(message);
	std::cout << std::endl;
}

void printnl() { std::cout << std::endl; }
