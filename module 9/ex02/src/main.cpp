#include "../inc/PmergeMe.hpp"

int parseNumber(std::string s) {
	size_t pos = 0;
	int nb = std::stoi(s, &pos);

	if (pos != s.length())
		throw std::invalid_argument("trailing characters");
	if (nb < 0)
		throw std::invalid_argument("negative number");

	return (nb);
}

int main(int argc, char *argv[]) {
	if (argc < 3)
		return (1);

	PmergeMe p;
	for (int i = 1; argv[i]; i++) {
		try {
			int nb = parseNumber(std::string(argv[i]));
			p.addNumber(nb);
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			return(1);
		}
	}
	p.sortVec();
	// p.sortDeq();
	// p.printResult();
	return (0);
}
