#ifndef DEFAULT_HPP
#define DEFAULT_HPP

#include <iostream>
#include <unistd.h>

#define str std::string

//errors
#define STREMPTY "This field can not be empty. Try again: "
#define NOCONTACTS "There are no contacts yet.\n"
#define WRONGCOMM "Not a valid command. \nValid commands are: ADD, SEARCH, EXIT"
#define WRONG "no🙅🚫"

//macros
#define WELCOME "\033[2J\033[H	Welcome To Phonebook!\n"
#define PROMPT_CMD "Please write a command from the list: ADD, SEARCH, EXIT 😊\n"
#define CONTACTADDEDD "Contact Added!\n"
#define SELECT_INDEX "Please select contact to view: "

void printnl();
void printnl(str message);
void print(str message);
void print(int nb);
void print(char c);



str get_input(str prompt);
str get_num_input(str prompt);
void print_goodbye();
void print_welcome();

bool all_of(str s, bool (*f)(char));
bool is_digit(char c);
bool is_space(char c);

#endif