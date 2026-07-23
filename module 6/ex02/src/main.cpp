#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

int main() {
	// Seed-dependent random generation, run a few times
	std::cout << "--- Testing generate() + identify(Base*) ---" << std::endl;
	{
		for (int i = 0; i < 5; i++) {
			Base* p = Base::generate();
			Base::identify(p);
			delete p;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "--- Testing identify(Base&) ---" << std::endl;
	{
		A a;
		B b;
		C c;

		Base& refA = a;
		Base& refB = b;
		Base& refC = c;

		Base::identify(refA);
		Base::identify(refB);
		Base::identify(refC);
	}

	return (0);
}