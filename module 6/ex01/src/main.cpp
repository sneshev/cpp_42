#include "../inc/Serializer.hpp"
#include <iostream>
#include <cassert>

int main(void) {
	Data original;
	original.index = 1;
	original.name = "Bobby";

	uintptr_t raw = Serializer::serialize(&original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original address:  " << &original << std::endl;
	std::cout << "Serialized value:  " << raw << std::endl;
	std::cout << "Deserialized addr: " << restored << std::endl;

	std::cout << std::endl;
	assert(restored == &original);
	std::cout << "Pointers match: " << (restored == &original ? "yes" : "no") << std::endl;

	std::cout << std::endl;
	// prove the deserialized pointer actually points to valid, unchanged data
	std::cout << "restored->index: " << restored->index << std::endl;
	std::cout << "restored->name: " << restored->name << std::endl;

	return 0;
}