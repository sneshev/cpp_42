#include "../inc/PmergeMe.hpp"

size_t comparisons = 0;

PmergeMe::PmergeMe() {
	// std::cout << GREEN << "PmergeMe Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	// std::cout << BLUE << "PmergeMe Copy constructor called" << RESET << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	// std::cout << BLUE << "PmergeMe Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_original = other._original;
		_vec = other._vec;
		_deq = other._deq;
		_vecUs = other._vecUs;
		_deqUs = other._deqUs;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {
	// std::cout << RED << "PmergeMe Destructor called" << RESET << std::endl;
}


void PmergeMe::addNumber(unsigned int n) {
	number nb;
	nb.val = n;
	_vec.push_back(nb);
	_deq.push_back(nb);
	_original.push_back(n);
}

int getNextA(int aIndex, int& jIndex, int &aSize, bool& stopOnNextJump) {
	// pick next number respecting the Jacobsthal sequence
	--aIndex;
	if (aIndex == Jacobsthal[jIndex - 1]) {
		jIndex += 1;
		aIndex = Jacobsthal[jIndex];
	}

	// clamp
	if (aIndex > aSize) {
		if (stopOnNextJump == true) {
			aSize = -1;
		} else {
			aIndex = aSize;
			stopOnNextJump = true;
		}
	}

	// edge case end
	if (aSize == Jacobsthal[jIndex - 1]) {
		aSize = -1;
	}

	return (aIndex);
}


void PmergeMe::sortVec() {
	if (_vec.size() < 2)
		throw std::runtime_error("sortVec: too few arguments");

	tp start = std::chrono::steady_clock::now();

	_vec = mergeInsertionSort(_vec);

	tp end = std::chrono::steady_clock::now();
	_vecUs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

void PmergeMe::sortDeq() {
	if (_deq.size() < 2)
		throw std::runtime_error("sortDeq: too few arguments");

	tp start = std::chrono::steady_clock::now();

	_deq = mergeInsertionSort(_deq);

	tp end = std::chrono::steady_clock::now();
	_deqUs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


// static void printNumbers(std::vector<unsigned int> numbers) {
// 	for (size_t i = 0; i < numbers.size(); ++i) {
// 		if (i == 6 && PRINTNUMBERS_CUT) {
// 			std::cout << "[...]";
// 			return ;
// 		}
// 		std::cout << numbers[i] << " ";
// 	}
// }

static void printNumbers(std::vector<number> numbers) {
	for (size_t i = 0; i < numbers.size(); ++i) {
		if (i == 6 && PRINTNUMBERS_CUT) {
			std::cout << "[...]";
			return ;
		}
		std::cout << numbers[i].val << " ";
	}
}



/*
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us*/
void PmergeMe::printResult() const {
	// std::cout << "Before: "; printNumbers(_original); std::cout << std::endl;
	// std::cout << "After: "; printNumbers(_vec); std::cout << std::endl;
	// std::cout << "Time to process a range of " << _original.size()
	// 	<< " elements with std::vector : " << _vecUs << "us" << std::endl;
	// std::cout << "Time to process a range of " << _original.size()
	// 	<< " elements with std::deque : " << _deqUs << "us" << std::endl;
	// if (PRINTNUMBERS_COMPARISONS == true) {
	// 	std::cout << "Number of comparisons: " << comparisons << std::endl;
	// }

	std::cout << comparisons << "\n";
	printNumbers(_vec);
}







/*

	1 3 5 7 8
	
	1-3  5-7  8
	std::pair<int, void*> {3, {1, nullptr}}
	std::pair<int, void*> {7, {5, nullptr}}
	8

	3(1) 7(5) 8
	
	
	
	37 
	137
	1357
	13578

	{3, {1, nullptr}}  {7, {5, nullptr}} 8









	1 3 5 7 8
	{1, nullptr}
	{3, nullptr}
	{5, nullptr}
	{7, nullptr}
	{8, nullptr}

	3(1)-7(5) 8
	{3, {1, nullptr}}
	{7, {5, nullptr}}
	8
	1 3 5 7 9 11 20 29 31 37 40
	37
	137
	1357
	13578
















	3 5 2 1 4
	{3, nullptr}
	{5, nullptr}
	{2, nullptr}
	{1, nullptr}
	{4, nullptr}

	5-3 2-1 4
	{5, {3, nullptr}}
	{2, {1, nullptr}}
	4

	5(3)-2(1) 4
	25
	125
	1235
	12345




	2 4 3 1 
	{2, nullptr}
	{4, nullptr}
	{3, nullptr}
	{1, nullptr}

	4-2 3-1
	{4, {2, nullptr}}
	{3, {1, nullptr}}

	4(2)-3(1)
	34
	134
	1234








	 2 1 3 

	 {2, nullptr}
	 {1, nullptr}
	 {3, nullptr}


	2-1 3
	{2, {1, nullptr}} //NO
	{3, nullptr}	  //NO
	2(1)-3			  //NO
	23				  //NO
	123				  //NO










	2 1
	1 2



	num {
		int val;
		int *remembers;
	}

	29 3 1 9 7 20 40 11 31 37 5

	29-3 9-1 20-7 40-11 37-31 //5
	{29, {3}}
	{9, {1}}
	{20, {7}}
	{40, {11}}
	{37, {31}}

	29(3)-9(1) 40(11)-20(7) //37(31) //5
	{29, {9{1}, 3}}
	{40, {20{7}, 11}}

	29-40
	{29, {9{1}, 3}}
	{40, {20{7}, 11}}

	9-29-40
	{9, {1}}
	{29, {3}}
	{40, {20{7}, 11}}

	9-20-29-40
	{9, {1}}
	{20, {7}}
	{29, {3}}
	{40, {11}}

	













	29 3 1 9 7 20 40 11 31 37 5


	29-3 9-1 20-7 40-11 37-31 //5
	{29, {3, nullptr}}
	{9, {1, nullptr}}
	{20, {7, nullptr}}
	{40, {11, nullptr}}
	{37, {31, nullptr}}
	5

	29(3)-9(1) 40(11)-20(7)  //37(31) //5
	{29, {9, {3, {1}}}}
	{40, {20, {11, {7}}}}

	29(9(3(1)))-40(20(11(7)))
	29-40

	9
	9 29 40
	9 20 29 40























	





	1 3 5 7 8

	13 57 8
	31 75 8
	
	37
	137
	1357
	13578





*/