#include <iostream>
#define str std::string

int main(int argc, char *argv[]) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			str s = argv[i];
			for (char &c : s) {
				c = toupper(c);
			}
			std::cout << s;
		}
		std::cout << std::endl;
	}
}