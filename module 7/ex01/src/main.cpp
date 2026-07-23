#include "../inc/iter.hpp"
#include <string>

void incrementInt(int &n) {
	n++;
}

void shout(std::string &s) {
	s += "!";
}


int main( void )
{
	std::cout << "-- int array --" << std::endl;
	{
		int intArr[] = {1, 2, 3, 4, 5};
		size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

		std::cout << "before: ";
		iter(intArr, intLen, print<int>);
		std::cout << std::endl;


		std::cout << "	iter(intArr, intLen, incrementInt)" << std::endl;
		iter(intArr, intLen, incrementInt);

		std::cout << "after increment: ";
		iter(intArr, intLen, print<int>);
		std::cout << std::endl << std::endl;
	}


	std::cout << "-- string array --" << std::endl;
	{
		std::string strArr[] = {"hello", "world", "foo"};
		size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

		std::cout << "before: ";
		iter(strArr, strLen, print<std::string>);
		std::cout << std::endl;

		std::cout << "	iter(strArr, strLen, shout)" << std::endl;
		iter(strArr, strLen, shout);

		std::cout << "after shout: ";
		iter(strArr, strLen, print<std::string>);
		std::cout << std::endl;
	}


    return 0;
}