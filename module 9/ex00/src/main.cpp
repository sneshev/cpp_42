#include "../inc/BitcoinExchange.hpp"


#define DB_FILENAME "./data.csv"



std::ifstream openFile(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	return (file);
}


int main(int argc, char* argv[]) {
	std::ifstream file = openFile(argc, argv);
	BitcoinExchange exchange(DB_FILENAME);

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		exchange.checkPrice(line);
	}
	return (0);
}
