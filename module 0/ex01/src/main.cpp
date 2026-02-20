#include "../includes/PhoneBook.hpp"

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