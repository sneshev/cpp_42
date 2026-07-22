#include "../inc/ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
		return (0);
	}
	else {
		std::string tests[] = { "0", "nan", "42.0f", "-inff", "+inf", "c", "2147483648", "-42"};

		for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
			std::cout << "=== Input: " << tests[i] << " ===" << std::endl;
			ScalarConverter::convert(tests[i]);
			std::cout << std::endl;
		}
	}

	return 0;
}