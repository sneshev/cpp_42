#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define COLOR "\033[30m"


class ClapTrap {
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		int			useEnergy();

	public:
		ClapTrap(const std::string inName);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printClapTrap();
};



#endif