#include "../includes/Zombie.hpp"

/*	It must allocate N Zombie objects in a single allocation. Then, it must initialize the
	zombies, giving each of them the name passed as a parameter. The function returns a
	pointer to the first zombie.
*/
Zombie* zombieHorde( int N, std::string name ) {
    if (N < 1) { return nullptr; }

	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}