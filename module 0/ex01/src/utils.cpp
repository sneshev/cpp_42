#include "../includes/header.hpp"


bool is_space(char c) {
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

bool is_digit(char c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool all_of(str s, bool (*f)(char)) {
	for (size_t i = 0; i < s.length(); i++ ) {
		if (!f(s[i]))
			return (false);
	}
	return (true);
}


#include <cstdlib>
void print_welcome() {
	std::system("clear");
	printnl(WELCOME);
}

void print_goodbye() {
	printnl("bye\n");
}



str get_input(str prompt) {
	str	input;
	print(prompt);
	while (1) {
		if (getline(std::cin, input).fail()) {
			std::cin.clear();
			continue;
		}
		else if (input.empty())
			printnl(STREMPTY);
		else if (all_of(input, is_space))
			printnl(STREMPTY);
		else
			break ;
	}
	return (input);
}

str get_num_input(str prompt) {
	str input = get_input(prompt);
	while(!all_of(input, is_digit)) {
		printnl(WRONG);
		input = get_input(prompt);
	}
	return (input);
}