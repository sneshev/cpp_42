#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		str		_name;
		Weapon	&_weapon;

	public:
		HumanA(Weapon &inWeapon);
		HumanA(str inName, Weapon &inWeapon);
		~HumanA();
		// void setWeapon(Weapon inWeapon);
		void attack();
};

#endif