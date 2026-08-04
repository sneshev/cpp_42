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

class number {
	public:
		int val;
		std::vector<number> remembers;

	bool operator<(const number& other) const {
		return val < other.val;
    }
};

class PmergeMe {
	private:
		std::vector<int> _vec;
		// std::deque<int>  _deq;

		// double _vecUs;
		// double _deqUs;

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


const int Jacobsthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2147483647/*intmax for safety*/};

/*
	
		v.size() = 2 			v.size() = 3
		aIndex = 1				aIndex = 
					->->->
					->->->			
		a1 a2					b1 a1 a2
		b1 b2		    	 		  b2





		v.size() = 3 			v.size() = 4
		aIndex = 2				aIndex = 
					->->->
					->->->			
		b1 a1 a2					b2 b1 a1 a2
		      b2		    	 		  




		a1 a2 a3 a4 a5				aIndex = 1;
		b1 b2 b3 b4 b5				current= 0 //1

		b1 a1 a2 a3 a4 a5			aIndex = 3;
		   b2 b3 b4 b5				current= 3 //4

		b2 b1 a1 a2 a3 a4 a5		aIndex = 2;
		            b3 b4 b5		current= 3 //4





















		a1 a2 a3 a4 a5				aIndex = 1;
		b1 b2 b3 b4 b5				current= 0 //1

		b1 a1 a2 a3 a4 a5			aIndex = 2;
		      b2 b3 b4 b5	    	current= 2 //3

		b2 b1 a1 a2 a3 a4 a5		aIndex = 3
		            b3 b4 b5		current= 4 //5

		b3 b2 b1 a1 a2 a3 a4 a5		aIndex = 4
		                  b4 b5		current= 6 //7

		b4 b3 b2 b1 a1 a2 a3 a4 a5	aIndex = 5
		                  	    b5	current= 8 //9

	// int numberIndex = aIndex*2 - 1;

*/