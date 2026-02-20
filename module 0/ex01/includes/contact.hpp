#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "default.hpp"

class Contact {
	private:
		str	_first_name;
		str	_last_name;
		str	_nickname;
		str	_phone_nbr;
		str	_secret;

	public:
		Contact();
		void setFirstName(const str &inFirstName);
		void setLastName(const str &inLastName);
		void setNickname(const str &inNickname);
		void setPhoneNumber(const str &inPhoneNumber);
		void setSecret(const str &inSecret);

		str getFirstName();
		str getLastName();
		str getNickname();
		str getPhoneNumber();
		str getSecret();
};


#endif