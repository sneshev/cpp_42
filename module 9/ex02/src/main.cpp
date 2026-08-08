#include "../inc/PmergeMe.hpp"
#include <random>

int parseNumber(std::string s) {
	size_t pos = 0;
	int nb = std::stoi(s, &pos);

	if (pos != s.length())
		throw std::invalid_argument("trailing characters");
	if (nb < 0)
		throw std::invalid_argument("negative number");

	return (nb);
}

std::random_device rd;
std::mt19937 gen(rd());
int randomNumber() {
	std::uniform_int_distribution<int> dist(0, INT32_MAX);
	return dist(gen);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: " << "too few arguments" << std::endl;
		return (1);
	}
	else if (argc == 2) {
		PmergeMe p;
		try {
			int size = parseNumber(std::string(argv[1]));

			for (int i = 0; i < size; i++) {
				p.addNumber(randomNumber());
			}
			p.sortVec();
			p.sortDeq();
			p.printResult();
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return(1);
		}
	}
	else {
		PmergeMe p;
		try {
			for (int i = 1; argv[i]; i++) {
				int nb = parseNumber(std::string(argv[i]));
				p.addNumber(nb);
			}
			p.sortVec();
			// p.sortDeq();
			p.printResult();
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return(1);
		}
	}

	return (0);
}


/*



	a1 
	b1 b2

	b1 a1 
	      b2    
		      size == 2




	a1 a2
	b1 b2 b3

	b1 a1 a2
	      b2 b3
					size == 3

	a1 a2 a3 a4
	b1 b2 b3 b4 b5

	b2 b3 b1 a1 a2 a3 a4
	                  b4 b5    
					  		  size == 7 




*/