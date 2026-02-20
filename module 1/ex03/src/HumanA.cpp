#include "../includes/HumanA.hpp"

HumanA::HumanA(Weapon &inWeapon) : _name("humanA"), _weapon(inWeapon) {
	std::cout << GREEN <<  "HumanA has been created" << RESET << std::endl;
}

HumanA::HumanA(str inName, Weapon &inWeapon) : _name(inName), _weapon(inWeapon) {
	std::cout << GREEN <<  "HumanA has been created" << RESET << std::endl;
}

HumanA::~HumanA() {
	std::cout << RED << "HumanA has been destroyed" << RESET << std::endl;
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

// void HumanA::setWeapon(Weapon inWeapon) {
// 	_weapon = inWeapon;
// }