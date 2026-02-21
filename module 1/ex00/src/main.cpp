#include "../includes/Zombie.hpp"


Zombie* newZombie( std::string inName );
void randomChump( std::string name );


int main() {
	randomChump("kitty");

	Zombie *zombie = newZombie("alona");
	zombie->announce();
	delete zombie;
}