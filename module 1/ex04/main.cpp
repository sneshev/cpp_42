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
#include <fstream>
#include <string>
#define str std::string
#define BADARGC "Argument count must be 3 (file and 2 strings)"
#define EMPTYSTR "Arguments can not be empty"
#define BADFILE "Error: Could not open file"
#define FILECREATE "Error: Could not create file"
bool error(str message) {
	std::cerr << message << std::endl;
	return (false);
}

bool is_valid_input(int argc, char *argv[]) {
	if (argc != 4) {
		return error(BADARGC);
	}
	for (int i = 1; i < 4; i++) {
		str s = argv[i];
		if (s.empty())
			return (error(EMPTYSTR));
	}
	return (true);
}


str replace_all(str &c, str s1, str s2) {
	
}

int main(int argc, char *argv[]) {
	if (!is_valid_input(argc, argv))
		return (1);
	
	std::ifstream inFile(argv[1]);
	if (!inFile) {
		error(BADFILE);
		return (1);
	}
	std::ofstream outFile(str(argv[1]) + ".replace");
	if (!outFile) {
		error(FILECREATE);
		return (1);
	}
	std::string content( 
		(std::istreambuf_iterator<char>(inFile)),
		std::istreambuf_iterator<char>()
	);
    content = replace_all(content, argv[2], argv[3]);
    outFile << content;
    return 0;

}