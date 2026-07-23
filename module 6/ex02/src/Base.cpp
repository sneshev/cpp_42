#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <ctime>

Base::Base() {
	std::cout << GREEN << "Base Default constructor called" << RESET << std::endl;
}

Base::Base(const Base& other) {
	std::cout << BLUE << "Base Copy constructor called" << RESET << std::endl;
	*this = other;
}

Base& Base::operator=(const Base& other) {
	std::cout << BLUE << "Base Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

Base::~Base() {
	std::cout << RED << "Base Destructor called" << RESET << std::endl;
}

Base* Base::generate() {
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	switch (std::rand() % 3) {
		case 0: return (new A());
		case 1: return (new B());
		default: return (new C());
	}
}

void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "ptr to A" << std::endl;
	}
	if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "ptr to B" << std::endl;
	}
	if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "ptr to C" << std::endl;
	}
}

void Base::identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "ref to A" << std::endl;
	} catch (std::bad_cast&) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "ref to B" << std::endl;
	} catch (std::bad_cast&) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "ref to C" << std::endl;
	} catch (std::bad_cast&) {}
}