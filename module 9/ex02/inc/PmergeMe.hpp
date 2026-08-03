#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

typedef struct s_number {
	int val;
	std::vector<s_number> remembers;
} number;

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

		double _vecUs;
		double _deqUs;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();


		void addNumber(unsigned int n);
		void sortVec() ;
		// void sortDeq() ;
		// void printResult() const ;


	/* internal for sorting */
	private:
		std::vector<number> makePairsVec(std::vector<number> vec, number &straggler);
		std::vector<number> sortVec(std::vector<number> vec);

		// void sortVec(std::vector<int> vec) ;
		// void sortDeq(std::deque<int> deq) ;
};
