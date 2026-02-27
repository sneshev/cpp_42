#include "../inc/ClapTrap.hpp"


	//	ORTHODOX CANONICAL FORM

ClapTrap::ClapTrap(
	const std::string& inName,
	unsigned int inHitPoints,
	unsigned int inEnergy,
	unsigned int inDamage
)
	: _name(inName),
	_hitPoints(inHitPoints),
	_energyPoints(inEnergy),
	_attackDamage(inDamage) 
{
	std::cout << GREEN << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& inName)
	: _name(inName)
	{
	std::cout << GREEN << "ClapTrap Default constructor called" << RESET << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << BLUE << "ClapTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
};

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << BLUE << "ClapTrap Copy constructor called" << RESET << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}


	//	MEMBER FUNCTIONS
void ClapTrap::attack(const std::string& target) {
	if (useEnergy() != -1) {
		std::cout << "ClapTrap " << _name << " attacks " <<  target << ", causing " << _attackDamage <<" points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (useEnergy() != -1) {
		_hitPoints += amount;
		std::cout << "Claptrap " << _name << " is repaired by " << amount << " hit points" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << "Claptrap " << _name << " took " << amount << " damage :(" << std::endl;
}

int ClapTrap::useEnergy() {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		return (1);
	}
	else {
		std::cout << _name << " doesnt have any " << ((_hitPoints <= 0) ? "hit" : "energy" ) << " points left" << std::endl;
		return (-1);
	}

}

void ClapTrap::printClapTrap() {
	std::cout << COLOR << "ClapTrap " << _name << " (" << _hitPoints << " hp, " << _energyPoints << "ep, " << _attackDamage << "dmg)" << RESET << std::endl;
}


	// GETTERS / SETTERS

std::string 	ClapTrap::getName()			{ return (_name); }
int 			ClapTrap::getHitPoints()	{ return (_hitPoints); }
unsigned int	ClapTrap::getEnergyPoints()	{ return (_energyPoints); }
unsigned int	ClapTrap::getAttackDamage()	{ return (_attackDamage); }

void ClapTrap::setHitPoints(unsigned int hp) 		{ _hitPoints = hp; }
void ClapTrap::setEnergyPoints(unsigned int energy)	{ _hitPoints = energy; }
void ClapTrap::setAttackDamage(unsigned int damage)	{ _hitPoints = damage; }