#include "../inc/ScavTrap.hpp"

int main() {
	ScavTrap a("bb");
	a.printScavTrap();
	a.attack("cc");
	a.printScavTrap();
	a.guardGate();
	a.beRepaired(77);
	a.printScavTrap();

	std::cout << std::endl;
	for (int i = 2; i > 0; i--) {
		a.takeDamage(100);
		a.printScavTrap();
	}
	a.beRepaired(1);
}