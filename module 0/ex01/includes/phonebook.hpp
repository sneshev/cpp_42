#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
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