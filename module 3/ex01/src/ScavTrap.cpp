#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string inName) : ClapTrap(inName, 100, 50, 20) {
	std::cout << GREEN << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap Destructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << BLUE << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		ScavTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	(void)other;
	// *this = other;
	std::cout << BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (useEnergy() != -1) {
		setHitPoints(getHitPoints() + amount);
		std::cout << "ScavTrap " << getName() << " is repaired by " << amount << " hit points" << std::endl;
	}
}

void ScavTrap::attack(const std::string& target) {
	if (useEnergy() != -1)
		std::cout << "ScavTrap " << getName() << " attacks " <<  target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;

}

void ScavTrap::takeDamage(unsigned int amount) {
	setHitPoints(getHitPoints() - amount);
	std::cout << "ScavTrap " << getName() << " took " << amount << " damage :(" << std::endl;
}

void ScavTrap::printScavTrap() {
	std::cout << COLOR << "ScavTrap " << getName() << " (" << getHitPoints() << " hp, " << getEnergyPoints() << "ep, " << getAttackDamage() << "dmg)" << RESET << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in gate keeper mode" << std::endl;
}