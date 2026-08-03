#pragma once

#include <iostream>
#include <stack>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void error();

class RPN {
	private:
		std::stack<int> _s;

		void evaluate(char sign);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void takeElement(char c);
		int  getResult();
};
