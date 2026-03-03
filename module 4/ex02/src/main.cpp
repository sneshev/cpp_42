#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
	// Animal* a = new Animal();
	// Animal aa;
	Animal* d = new Dog();
	Animal* c = new Cat();
	// a->makeSound();
	c->makeSound();
	d->makeSound();
	// delete a;
	delete c;
	delete d;


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