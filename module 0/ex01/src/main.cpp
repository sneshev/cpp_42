#include "../includes/phonebook.hpp"

//errors
#define STREMPTY "This field can not be empty. Try again: "
#define NOCONTACTS "There are no contacts yet.\n"
#define WRONGCOMM "Not a valid command. \nValid commands are: ADD, SEARCH, EXIT"
#define WRONG "no🙅🚫"

//macros
#define PROMPT_CMD "Please write a command from the list: ADD, SEARCH, EXIT 😊\n"
#define CONTACTADDEDD "Contact Added!\n"
#define SELECT_INDEX "Please select contact to view: "


void print_welcome() {
	printnl("welcome 2 phonebok\n");
}

void print_goodbye() {
	printnl("bye\n");
}

bool is_space(char c) {
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

str get_input(str prompt) {
	str	input;
	print(prompt);
	while (1) {
		if (getline(std::cin, input).fail()) {
			std::cin.clear();
			continue;
		}
		else if (input.empty())
			printnl(STREMPTY);
		else if (std::all_of(input.begin(), input.end(), ::is_space))
			printnl(STREMPTY);
		else
			break ;
	}
	return (input);
}

str get_num_input(str prompt) {
	str input = get_input(prompt);
	while(!std::all_of(input.begin(), input.end(), ::isdigit)) {
		printnl(WRONG);
		input = get_input(prompt);
	}
	return (input);
}

void do_add(PhoneBook &phoneBook) {
	Contact contact;
	contact.setFirstName(get_input("First name: "));
	contact.setLastName(get_input("Last name: "));
	contact.setNickname(get_input("Nickname: "));
	contact.setPhoneNumber(get_num_input("Phone number: "));
	contact.setSecret(get_input("Darkest secret: "));
	phoneBook.addContact(contact);
	printnl(CONTACTADDEDD);
}

void do_search(PhoneBook &phoneBook) {
	{
		if (phoneBook.getCount() >= 1) {
			phoneBook.displayContacts();
			int index = -1;
			while (1) {
				str input = get_num_input(SELECT_INDEX);
				index = std::stoi(input);
				if (index < 1 || index > MAXCOUNT || index > phoneBook.getCount())
					printnl(WRONG);
				else
					break ;
			};
			phoneBook.showContact(index - 1);
		}
		else
			printnl(NOCONTACTS);
	}
}

int main() {
	print_welcome();

	PhoneBook phoneBook;
	str input = get_input(PROMPT_CMD);

	while (input != "EXIT")
	{
		if (input == "ADD") {
			do_add(phoneBook);
		} 
		else if (input == "SEARCH") {
			do_search(phoneBook);
		} 
		else {
			printnl(WRONG);
			printnl();
		}

		input = get_input(PROMPT_CMD);
	}
	print_goodbye();
	return 0;
}