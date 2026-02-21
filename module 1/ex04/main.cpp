/*	Create a program that takes three parameters in the following order: a filename and
	two strings, s1 and s2.
	It must open the file <filename> and copy its content into a new file
	<filename>.replace, replacing every occurrence of s1 with s2.
	Using C file manipulation functions is forbidden and will be considered cheating. All
	the member functions of the class std::string are allowed, except replace. Use them
	wisely!
	Of course, handle unexpected inputs and errors. You must create and turn in your
	own tests to ensure that your program works as expected.
*/
#include <iostream>
#define str std::string
#define BADARGC "Argument count must be 3 (file and 2 strings)"



bool error(str message) {
	std::cout << message << std::endl;
	return (false);
}

bool is_valid_input(int argc, char *argv[], int *fd) {
	(void)argv;
	(void)fd;
	if (argc != 4) {
		return error(BADARGC);
	}
	return (true);
}


int main(int argc, char *argv[]) {
	int fd;
	if (!is_valid_input(argc, argv, &fd))
		return (1);
}