#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(std::string inName) : ClapTrap(inName, 100, 100, 30) {
	std::cout << GREEN << "FragTrap Default constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap Destructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << BLUE << "FragTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		FragTrap::operator=(other);
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	(void)other;
	// *this = other;
	std::cout << BLUE << "FragTrap Copy constructor called" << RESET << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (useEnergy() != -1) {
		setHitPoints(getHitPoints() + amount);
		std::cout << "FragTrap " << getName() << " is repaired by " << amount << " hit points" << std::endl;
	}
}

void FragTrap::attack(const std::string& target) {
	if (useEnergy() != -1)
		std::cout << "FragTrap " << getName() << " attacks " <<  target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;

}

void FragTrap::takeDamage(unsigned int amount) {
	setHitPoints(getHitPoints() - amount);
	std::cout << "FragTrap " << getName() << " took " << amount << " damage :(" << std::endl;
}

void FragTrap::printFragTrap() {
	std::cout << COLOR << "FragTrap " << getName() << " (" << getHitPoints() << " hp, " << getEnergyPoints() << "ep, " << getAttackDamage() << "dmg)" << RESET << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " high fives guy" << std::endl;
}