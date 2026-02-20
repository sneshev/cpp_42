#include "../includes/phonebook.hpp"

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



static void display_contact(int i, str a, str b, str c, str d) {
	print(i);
	print(" | ");
	print(a);
	print(" | ");
	print(b);
	print(" | ");
	print(c);
	print(" | ");
	print(d);
	printnl();
} 

/*	Display the saved contacts as a list of 4 columns: index, first name, last
	name and nickname.
	◦ Each column must be 10 characters wide. A pipe character (’|’) separates
	them. The text must be right-aligned. If the text is longer than the column,
	it must be truncated and the last displayable character must be replaced by a
	dot (’.’).
	◦ Then, prompt the user again for the index of the entry to display. If the index
	is out of range or wrong, define a relevant behavior. Otherwise, display the
	contact information, one field per line. 
*/
void PhoneBook::displayContacts() const {
	if (_count <= 0)	return ;

	for (int i = 0; i < _count && i < MAXCOUNT; i++) {
		Contact c = getContact(i);
		display_contact(
			i + 1,
			c.getFirstName(),
			c.getLirstName(),
			c.getNickname(),
			c.getPhoneNumber()
		);
	}
	printnl();
	
}