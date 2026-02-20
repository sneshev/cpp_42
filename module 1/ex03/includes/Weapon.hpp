#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#define str std::string

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"


class Weapon {
	private:
		str _type;

	public:
		Weapon();
		Weapon(str inType);
		~Weapon();
		void		setType(const str &inType);
		const str	getType() const;

};

#endif
