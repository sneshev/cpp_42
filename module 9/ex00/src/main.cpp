#include "../inc/BitcoinExchange.hpp"


#define DB_FILENAME "./data.csv"



// std::ifstream openFile(int argc, char* argv[]) {
// 	if (argc != 2)
// 		exit(giveError(ERR_BADFILE));

// 	std::ifstream file(argv[1]);
// 	if (!file.is_open())
// 		exit(giveError(ERR_BADFILE));

// 	return (file);
// }


int main(int argc, char* argv[]) {
	// std::ifstream file = openFile(argc, argv);
	(void)argc; (void)argv;
	BitcoinExchange exchange(DB_FILENAME);
	exchange.printDB();

	return (0);
}
