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
		void sortDeq() ;
		void printResult() const ;


	/* internal for sorting */
	private:
		std::vector<std::pair<int, void *>> makePairsVec(std::vector<std::pair<int, void *>> vec, int &straggler);

		void sortVec(std::vector<std::pair<int, void *>> vec);
		// void sortVec(std::vector<int> vec) ;
		void sortDeq(std::deque<int> deq) ;
};
