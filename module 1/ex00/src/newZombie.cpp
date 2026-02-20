#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string inName ) {
	return (new Zombie(inName));
}