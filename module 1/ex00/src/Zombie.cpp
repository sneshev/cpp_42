#include "../includes/Zombie.hpp"

Zombie::Zombie(void) : _name("zombie") {
	std::cout << GREEN << _name << " has been created" << "\033[0m" << std::endl;
}

Zombie::Zombie(str inName) : _name(inName){
	std::cout << GREEN << _name << " has been created" << "\033[0m" << std::endl;
}

void Zombie::setName(const str &inName) {
	_name = inName;
}

Zombie::~Zombie() {
	std::cout << RED << _name << " has been destroyed" << "\033[0m" << std::endl;
}

str Zombie::getName() {
	return _name;
}


void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}