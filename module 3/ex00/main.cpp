#include "ClapTrap.hpp"

int main() {
	ClapTrap jiji("jiji");
	jiji.printClapTrap();
	jiji.attack("joan");
	jiji.printClapTrap();
	jiji.takeDamage(5);
	jiji.printClapTrap();
	jiji.beRepaired(6);
	jiji.printClapTrap();

	std::cout << std::endl;
	for (int i = 0; i < 10; i ++) {
		jiji.attack("joan");
		jiji.printClapTrap();
	}
}