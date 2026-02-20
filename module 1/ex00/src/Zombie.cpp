#include "../includes/Zombie.hpp"

Zombie::Zombie(void) : _name("zombie") {
	std::cout << GREEN << _name << " has been created" << RESET << std::endl;
}

Zombie::Zombie(str inName) : _name(inName){
	std::cout << GREEN << _name << " has been created" << RESET << std::endl;
}

void Zombie::setName(const str &inName) {
	_name = inName;
}

Zombie::~Zombie() {
	std::cout << RED << _name << " has been destroyed" << RESET << std::endl;
}

str Zombie::getName() {
	return _name;
}


void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}