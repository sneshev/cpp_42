/*
		Contact();
		void setFirstName(const str &inFirstName);
		void setLastName(const str &inLastName);
		void setNickname(const str &inNickname);
		void setPhoneNumber(const str &inPhoneNumber);
		void setDarkestSecret(const str &inSecret);
*/

#include "../includes/Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const str &inFirstName)		{ _first_name = inFirstName; }
void Contact::setLastName(const str &inLastName)		{ _last_name = inLastName; }
void Contact::setNickname(const str &inNickname)		{ _nickname = inNickname; }
void Contact::setPhoneNumber(const str &inPhoneNumber)	{ _phone_nbr = inPhoneNumber; }
void Contact::setSecret(const str &inSecret)			{ _secret = inSecret; }

str Contact::getFirstName()		{ return _first_name; }
str Contact::getLastName()		{ return _last_name; }
str Contact::getNickname()		{ return _nickname; }
str Contact::getPhoneNumber()	{ return _phone_nbr; }
str Contact::getSecret() 		{ return _secret; }
