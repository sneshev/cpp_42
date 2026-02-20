#include "phonebook.hpp"

#define STREMPTY "This field can not be empty. Try again: "
#define NOCONTACTS "There are no contacts yet."
#define WRONGCOMM "Not a valid command. \nValid commands are: ADD, SEARCH, EXIT"

#define PROMPT_CMD "CMD?"

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

void print_goodbye() {
	printnl("bye");
}

str get_input(str prompt) {
	str	input;
	printnl(prompt);
	while (1) {
		if (getline(std::cin, input).fail()) {
			std::cin.clear();
			continue;
		}
		if (input.empty())
			printnl(STREMPTY);
		else
			break ;
	}
	return (input);
}

// int	add_contact(Contact &contact) {
	
// 	return (1);
// }

// Contact get_contact() {
	
// }

int main() {
	print_welcome();
	PhoneBook phoneBook;
	str input = get_input(PROMPT_CMD);

	while (input != "EXIT") {
		// printnl("opa");
		if (input == "ADD") {
			// Contact new_contact = get_contact();
			// add_contact(new_contact);
		}
		else if (input == "SEARCH") {
			if (phoneBook.getCount() >= 1) {
				// search(phoneBook);
				printnl("ih");
			}
			else
				printnl(NOCONTACTS);
		}
		else
			printnl(WRONGCOMM);
		input = get_input(PROMPT_CMD);
	}
	print_goodbye();

	return 0;
}