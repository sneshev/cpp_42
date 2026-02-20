#include "../includes/HumanB.hpp"

HumanB::HumanB() : _name("humanB") {
	std::cout << GREEN <<  "HumanB has been created" << RESET << std::endl;
}

HumanB::HumanB(str inName) : _name(inName) {
	std::cout << GREEN <<  "HumanB has been created" << RESET << std::endl;
}

HumanB::~HumanB() {
	std::cout << RED << "HumanB has been destroyed" << RESET << std::endl;
}

void HumanB::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &inWeapon) {
	_weapon = &inWeapon;
}