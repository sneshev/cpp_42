#include "../includes/phonebook.hpp"

//errors
#define STREMPTY "This field can not be empty. Try again: "
#define NOCONTACTS "There are no contacts yet.\n"
#define WRONGCOMM "Not a valid command. \nValid commands are: ADD, SEARCH, EXIT"
#define WRONG "no🙅🚫"

//macros
#define WELCOME "\033[2J\033[H	Welcome To Phonebook!\n"
#define PROMPT_CMD "Please write a command from the list: ADD, SEARCH, EXIT 😊\n"
#define CONTACTADDEDD "Contact Added!\n"
#define SELECT_INDEX "Please select contact to view: "

#include <cstdlib>
void print_welcome() {
	std::system("clear");
	printnl(WELCOME);
}

void print_goodbye() {
	printnl("bye\n");
}

bool is_space(char c) {
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

bool is_digit(char c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool all_of(str s, bool (*f)(char)) {
	for (size_t i = 0; i < s.length(); i++ ) {
		if (!f(s[i]))
			return (false);
	}
	return (true);
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
		else if (all_of(input, is_space))
			printnl(STREMPTY);
		else
			break ;
	}
	return (input);
}

str get_num_input(str prompt) {
	str input = get_input(prompt);
	while(!all_of(input, is_digit)) {
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
			printnl();
			printnl();
			print("Information about contact ");
			print(index);
			printnl(":");
			printnl();
			phoneBook.showContact(index - 1);
			sleep(1);
			printnl();
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