#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

#define ANIMALCOUNT 10

int main()
{
	Animal* animals[ANIMALCOUNT];

	for (int i = 0; i < ANIMALCOUNT; i++) {
		if (i % 2) {
			animals[i] = new Cat();
		} else {
			animals[i] = new Dog();
		}
	}
	for (int i = 0; i < ANIMALCOUNT; i++) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < ANIMALCOUNT; i++) {
		delete animals[i];
	}

	
	// Animal* a = new Animal();
	// Animal* d = new Dog();
	// Animal* c = new Cat();
	// a->makeSound();
	// c->makeSound();
	// d->makeSound();
	// delete a;
	// delete c;
	// delete d;




	// Dog *d1 = new Dog();
	// d1->setIdea(0, "food");
	// Dog *d2 = new Dog();
	// *d2 = *d1;
	// Dog *d3 = new Dog(*d1);
	// std::cout << d1->getIdea(0) << std::endl;
	// std::cout << d2->getIdea(0) << std::endl;
	// std::cout << d3->getIdea(0) << std::endl;

	// delete(d1);
	// delete(d2);
	// delete(d3);
	return 0;
}