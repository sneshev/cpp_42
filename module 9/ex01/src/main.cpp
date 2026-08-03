#include "../inc/RPN.hpp"

void error() {
	std::cout << "Error" << std::endl;
	exit(1);
}

int main(int argc, char* argv[]) {
	if (argc != 2)
		error();

	RPN rpn;
	const char* s = argv[1];	
	try {
		for (int i = 0; s[i]; i++) {
			if (s[i] == ' ')
				continue;
			rpn.takeElement(s[i]);
		}
		int res = rpn.getResult();
		std::cout << res << std::endl;
	} catch (std::exception& s) {
		error();
	}

	return (0);
}
