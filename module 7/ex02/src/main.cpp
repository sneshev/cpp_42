#include "../inc/Array.hpp"

int main() {
	std::cout << "===Default constructor===" << std::endl;
	{
		Array<int> empty;
		std::cout << "empty.size() = " << empty.size() << std::endl;
		std::cout << std::endl;
	}

	Array<int> a(5);
	std::cout << "===Constructor with n, default-initialized elements===" << std::endl;
	{
		std::cout << "a.size() = " << a.size() << std::endl;
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl; // should all be 0

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = (i + 1) * 10;
		std::cout << std::endl;
	}

	std::cout << "===Copy constructor: deep copy check===" << std::endl;
	{
		Array<int> b(a);
		b[0] = 999;
		std::cout << "after modifying b[0]: a[0]=" << a[0] << " b[0]=" << b[0] << std::endl;
		std::cout << std::endl;
	}

	std::cout << "===Assignment operator: deep copy check===" << std::endl;
	{
		Array<int> c;
		c = a;
		c[1] = 777;
		std::cout << "after modifying c[1]: a[1]=" << a[1] << " c[1]=" << c[1] << std::endl;
		std::cout << std::endl;
	}

	std::cout << "===Out-of-bounds access -> exception===" << std::endl;
	{
		try {
			std::cout << a[100] << std::endl;
		} catch (std::exception& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "===non-primitive type===" << std::endl;
	{
		Array<std::string> strs(3);
		strs[0] = "hello";
		strs[1] = "world";
		Array<std::string> strsCopy(strs);
		strsCopy[0] = "changed";
		std::cout << "strs[0]=" << strs[0] << "\nstrsCopy[0]=" << strsCopy[0] << std::endl;
		std::cout << std::endl;
	}

	return 0;
}