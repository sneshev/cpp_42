#include "../includes/Weapon.hpp"

Weapon::Weapon() : _type( "unknown weapon" ) {
	std::cout << GREEN <<  "weapon has been created" << RESET << std::endl;
}

Weapon::Weapon(str inType) : _type(inType) {
	std::cout << GREEN <<  "weapon has been created" << RESET << std::endl;
}

Weapon::~Weapon() {
	std::cout << RED << "weapon has been destroyed" << RESET << std::endl;
}

const str Weapon::getType() const{
	return (_type);
}

void Weapon::setType(const str &inType) {
	_type = inType;
}