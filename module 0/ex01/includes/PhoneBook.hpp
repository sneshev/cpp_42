#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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

#include "Contact.hpp"
#define MAXCOUNT 8
class PhoneBook {
	private:
		Contact _contacts[MAXCOUNT];
		int		_count;
	
	public:
		PhoneBook();
		const Contact&	getContact(int index) const;
		void			showContact(int index) const;
		void			addContact(Contact contact);
	    int				getCount() const;
		void			displayContacts() const;
};

#endif