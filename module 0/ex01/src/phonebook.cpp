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

void PhoneBook::showContact(int index) const {
	Contact c = getContact(index);
	print("First Name: ");		printnl(c.getFirstName());
	print("Last Name: ");		printnl(c.getLastName());
	print("Nickname: ");		printnl(c.getNickname());
	print("Phone number: ");	printnl(c.getPhoneNumber());
	print("Darkest secret: ");	printnl(c.getSecret());
}

void PhoneBook::addContact(Contact inContact) {
	int index = _count % 8;
	_count++;
	if (_count > MAXCOUNT * 2)
		_count -= MAXCOUNT;

	_contacts[index] = inContact;
}

bool is_space(char c);

static void print_attribute(str a) {
	int len = a.length();
	if (len < 10) {
		for (int i = 0; i < 10 - len; i++)
			print(" ");
	}
	for (int i = 0; i < len; i ++) {
		if (len > 10 && i == 9) {
			print(".");
			break ;
		}
		if (!is_space(a[i]))
			print(a[i]);
		else
			print(" ");
	}
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
		print("|");
		print(i + 1);
		print("|");
		print_attribute(c.getFirstName());
		print("|");
		print_attribute(c.getLastName());
		print("|");
		print_attribute(c.getNickname());
		print("|");
		printnl();
	}
	printnl();
	
}