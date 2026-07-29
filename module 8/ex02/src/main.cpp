#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main() {

	std::cout << "Subject example" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5); mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl; ++it;
		}

		std::stack<int> s(mstack);
		std::cout << "sliced size: " << s.size() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Compare against std::list output (same push order)" << std::endl;
	{
		std::list<int> lstack;
		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int, std::list<int>> s(lstack);
		std::cout << "sliced size: " << s.size() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Copy ctor / assignment" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		MutantStack<int> copy(mstack);
		MutantStack<int> assigned;
		assigned = mstack;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}