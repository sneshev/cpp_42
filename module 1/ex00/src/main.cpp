#include "../includes/Zombie.hpp"


Zombie* newZombie( std::string inName );


int main() {
	Zombie zombie;
	Zombie zombie2;
	Zombie zombie3("jiji");
	zombie.setName("jonny");
	zombie.announce();
	zombie2.announce();
	zombie3.announce();

	Zombie *zombie4 = newZombie("alona");
	zombie4->announce();
	delete zombie4;
}