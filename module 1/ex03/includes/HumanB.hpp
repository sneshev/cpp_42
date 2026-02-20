#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"


class HumanB {
	private:
		str		_name;
		Weapon	*_weapon;

	public:
		HumanB();
		HumanB(str inName);
		~HumanB();
		void setWeapon(Weapon &inWeapon);
		void attack();
};

#endif