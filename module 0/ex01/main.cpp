#include "phonebook.hpp"

#define STREMPTY "This field can not be empty. Try again: "

void print(str message) {
	std::cout << message;
}

void printnl(str message) {
	print(message);
	std::cout << std::endl;
}

void print_welcome() {
	printnl("welcome 2 phonebok");
}

str get_input(str prompt) {
	str	input;
	printnl(prompt);
	do {
		if (getline(std::cin, input).fail()) {
			std::cin.clear();
		if (input.empty())
			printnl(STREMPTY);
		}
	} while ();
}

int main() {
	print_welcome();
	str input = get_input();

	while (/*input != NULL && */ input != "EXIT") {
	printnl("opa");
	str input = get_input();	
	}

	return 0;
}