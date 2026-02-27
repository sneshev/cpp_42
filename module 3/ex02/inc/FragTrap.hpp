#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string inName);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(FragTrap const& other);
		~FragTrap();

		void	attack(const std::string& target) override;
		void	takeDamage(unsigned int amount) override;
		void	beRepaired(unsigned int amount) override;
		void	printFragTrap();
		void	highFivesGuys(void);
};







#endif