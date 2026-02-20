#include "phonebook.hpp"


PhoneBook::PhoneBook() : _count(0) {

}

int PhoneBook::getCount() const {
	return _count;
}

const Contact&	PhoneBook::getContact(int index) const {
	if (index < 0 || index >= _count || index >= MAXCOUNT)
		throw std::out_of_range("Invalid contact index");

	return (_contacts[index]);
}

void PhoneBook::addContact(Contact inContact) {
	int index = _count % 8;
	_count++;
	if (_count > MAXCOUNT * 2)
		_count -= MAXCOUNT;

	_contacts[index] = inContact;
}

void PhoneBook::displayContacts() const {
	
}