#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <chrono>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#define tp std::chrono::steady_clock::time_point

#define PRINTNUMBERS_CUT 0
// #define PRINTNUMBERS_CUT 0
#define PRINTNUMBERS_COMPARISONS 1
// #define PRINTNUMBERS_comparisons 0

// follows the formula [     J[i] = J[i-1] + (2 * J[i-2])    ] 
const int Jacobsthal[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2147483647/*intmax for safety*/};


extern size_t comparisons;

struct number {
	int val;
	std::vector<number> remembers;
};

class PmergeMe {
	private:
		std::vector<unsigned int> _original;
		std::vector<number> _vec;
		std::deque<number>  _deq;

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


};

template <typename Container>
void makePairs(Container& vec) {
	Container paired;

	for (typename Container::iterator it = vec.begin(); it != vec.end(); ++it) {

		// pick the 2 neighboring numbers (or put odd one in straggler)
		number nb = *it;
		++it;

		// push number into bigger number's remember vector
		if (nb.val > (*it).val) {
			nb.remembers.push_back(*it);
			paired.push_back(nb);
		}
		else {
			(*it).remembers.push_back(nb);
			paired.push_back(*it);
		}
		++comparisons;
	}
	vec = paired;
}

// size will always be even
template <typename Container>
static void insertElement(Container& v, number& n, size_t size) {
	if (size == 0) {
		v.insert(v.begin(), n);
		return ;
	}

	size_t low = 0, high = size;
	while (low < high) {
		size_t mid = low + (high-low)/2;

		++comparisons;
		if (v[mid].val > n.val)
			high = mid;
		else {
			low = mid + 1;
		}
	}

	v.insert(v.begin() + low, n);
}


int getNextA(int aIndex, int& jIndex, int &aSize, bool& stopOnNextJump);

template <typename Container>
static void putBackLosers(Container& v, number& straggler) {
	int jIndex = 1;
	int aIndex = 1;
	Container tmpVec = v;
	bool stopOnNextJump = false;

	// pop all the bs from this level out of v
	int aSize = v.size();
	for (int i = 0; i < aSize; i++) {
		if (v[i].remembers.size() >= 1)
			v[i].remembers.pop_back();
	}

	// place straggler at end of b chain
	if (straggler.val != -1) {
		number stragglerParent; stragglerParent.val = -1;
		stragglerParent.remembers.push_back(straggler);
		tmpVec.push_back(stragglerParent);
		aSize += 1;
	}


	for (size_t i = 0; aIndex <= aSize; ++i) {
		// get next a from tmp main chain
		number& currentA = tmpVec[aIndex - 1];

		// insert b to the main chain
		if (currentA.remembers.size() >= 1) {
			number b = currentA.remembers.back();
			size_t size = (aIndex-1) + i;
			if (currentA.val == -1) { --size; } // straggler
			insertElement(v, b, size);
		}

		// jump to next a respecting the sequence
		aIndex = getNextA(aIndex, jIndex, aSize, stopOnNextJump);
	}

}


template <typename Container>
Container mergeInsertionSort(Container vec) { 
	if (vec.size() <= 2) { // start sorted main chain
		if (vec.begin()->val > vec.rbegin()->val) {
			std::swap(*vec.begin(), *vec.rbegin());
		}
		++comparisons;
		return vec;
	}

	number straggler; straggler.val = -1;
	if (vec.size() % 2 == 1) {
		straggler = vec.back(); vec.pop_back();
	}

	// pair each 2 numbers
	if (vec.size() > 2) {
		makePairs(vec);
	}

	// recursion 
	vec = mergeInsertionSort(vec);

	// insert smaller numbers to the main chain
	putBackLosers(vec, straggler);

	// return from this level 
	return (vec);
}

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


		1 3 5 11 21 43 ...
	a = 5;
	i = 3;

		b3 b1 a1 b2 a2 a3 a4 a5
		                  b4 b5







		a1 a2 a3 a4 a5				aIndex = 1;
		b1 b2 b3 b4 b5				current= 0 //1

		b1 a1 a2 a3 a4 a5			aIndex = 3;
		   b2 b3 b4 b5				current= 3 //4

		b2 b1 a1 a2 a3 a4 a5		aIndex = 2;
		            b3 b4 b5		current= 3 //4








		x x x x x x












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