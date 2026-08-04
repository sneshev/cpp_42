#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << GREEN << "PmergeMe Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	std::cout << BLUE << "PmergeMe Copy constructor called" << RESET << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	std::cout << BLUE << "PmergeMe Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

PmergeMe::~PmergeMe() {
	std::cout << RED << "PmergeMe Destructor called" << RESET << std::endl;
}



void PmergeMe::addNumber(unsigned int n) {
	_vec.push_back(n);
}

std::vector<number> PmergeMe::makePairsVec(std::vector<number> vec, number &straggler) {
	std::vector<number> paired;

	for (std::vector<number>::iterator it = vec.begin(); it != vec.end(); ++it) {
		number nb = *it;
		++it;
		if (it == vec.end()) {
			straggler = nb;
			break;
		}
		else {
			if (nb.val > (*it).val) {
				nb.remembers.push_back(*it);
				paired.push_back(nb);
			}
			else {
				(*it).remembers.push_back(nb);
				paired.push_back(*it);
			}
		}
	}

	return (paired);
}

// static int getNextA(int aIndex, int& jIndex) {
// 	--aIndex;
// 	if (aIndex == Jacobsthal[jIndex - 1]) {
// 		jIndex += 1;
// 		aIndex = Jacobsthal[jIndex];
// 	}
// 	return (aIndex);
// }

// static void clampA(int& a, int& aSize, bool& stop) {
// 			if (stop == true) {
// 				aSize = -1;
// 			}
// 			else {
// 				a = aSize;
// 				stop = true;
// 			}
// }

static void putBackLosers(std::vector<number>& v, number straggler) {
	// int jIndex = 1;
	int aIndex = 1;
	// bool stopOnNextJump = false;

	int aSize = v.size();
	while (aIndex <= aSize) {
		// get next a from main chain
		number& currentA = v[aIndex*2 - 2];

		// insert b to the main chain
		if (currentA.remembers.size() >= 1) {
			number b = currentA.remembers.back();
			currentA.remembers.pop_back();
			v.insert(std::lower_bound(v.begin(), v.end(), b), b);
		}

		// jump to next a respecting the sequence
		aIndex++;
		// aIndex = getNextA(aIndex, jIndex);
		// if (aIndex > aSize) {
		// 	clampA(aIndex, aSize, stopOnNextJump);
		// }
	}

	if (straggler.val != -1) {
		v.insert(std::lower_bound(v.begin(), v.end(), straggler), straggler);
	}
}

std::vector<number> PmergeMe::sortVec(std::vector<number> vec) { 
	if (vec.size() <= 2) {
		if (vec.begin()->val > vec.rbegin()->val)
			std::swap(*vec.begin(), *vec.rbegin());
		return vec;
	}

	// pair each 2 numbers (big remembers small)
	number straggler; straggler.val = -1;
	std::vector<number> pairs = makePairsVec(vec, straggler);

	// recursion
	std::vector<number> newVec = sortVec(pairs);

	// insert smaller numbers to the main chain
	putBackLosers(newVec, straggler);

	// return from this level 
	return (newVec);
}

void PmergeMe::sortVec() {
	if (_vec.size() < 2)
		throw std::runtime_error("sortVec: too few arguments");

	std::vector<int>::iterator it;

	std::vector<number> numberVector;
	for (it = _vec.begin(); it != _vec.end(); ++it) {
		number n;
		n.val = *it;
		numberVector.push_back(n);
	}
	std::vector<number> v = sortVec(numberVector);

	for (std::vector<number>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << it->val << " ";
	}
	std::cout << std::endl;
}












// void PmergeMe::sortDeq() {


// }





// void PmergeMe::sortVec(std::vector<int> vec) { 
	// if (vec.size() < 2)
		// return ;
	// int straggler = -1;
	// std::vector<std::pair<int, int>> pairs = makePairsVec(straggler);
// 
	// std::vector<std::pair<int, int>> bigFromPair;
	// std::vector<std::pair<int, int>> smallFromPair;
	// indexPairs(pairs, bigFromPair, smallFromPair);
// 
	// 
// }





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