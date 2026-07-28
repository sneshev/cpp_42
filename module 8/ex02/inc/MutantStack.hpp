#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack()
			: std::stack<T>()
		{ }
		
		MutantStack(const MutantStack& other)
			: std::stack<T>(other)
		{ }

		MutantStack& operator=(const MutantStack& other) {
			std::stack<T>::operator=(other);
			return (*this);
		}

		~MutantStack() 
		{ }



		typedef typename std::deque<T>::iterator iterator;

		iterator begin() {
			return (this->c.begin());
		}

		iterator end() {
			return (this->c.end());
		}
};
