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

	protected:
		ClapTrap(
			const std::string& inName,
			unsigned int inHitPoints,
			unsigned int inEnergy,
			unsigned int inDamage
		);
		int				useEnergy();
		std::string		getName();
		int				getHitPoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoints(unsigned int energy);
		void			setAttackDamage(unsigned int damage);


	public:
		ClapTrap(const std::string& inName);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printClapTrap();
};



#endif