#include "../inc/Span.hpp"
#include <vector>
#include <list>

int main() {

	std::cout << "---- Subject example ----" << std::endl;
	{
		Span sp(5);
		sp.addNumber(6); 
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; // 11 - 9 = 2
		std::cout << sp.longestSpan() << std::endl;  // 17 - 3 = 14
	}
	std::cout << std::endl;


	std::cout << "---- Full container throws ----" << std::endl;
	{
		try {
			Span full(1);
			full.addNumber(1);
			full.addNumber(2);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;


	std::cout << "---- <2 elements throws ----" << std::endl;
	{
		try {
			Span empty(5);
			empty.shortestSpan();
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	
	std::cout << "---- addNumbers: vector ----" << std::endl;
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(100);
		v.push_back(-20);
		Span sv(3);
		sv.addNumbers(v.begin(), v.end());
		std::cout << sv.longestSpan() << std::endl; // 100 - (-20) = 120
	}
	std::cout << std::endl;

	
	std::cout << "---- addNumbers: raw array ----" << std::endl;
	{
		int arr[3] = {5, -5, 0};
		Span sa(3);
		sa.addNumbers(arr, arr + 3);
		std::cout << sa.longestSpan() << std::endl; // 5 - (-5) = 10
	}
	std::cout << std::endl;
	
	std::cout << "---- addNumbers: list ----" << std::endl;
	{
		std::list<int> l;
		l.push_back(7);
		l.push_back(-2);
		l.push_back(2);
		Span sl(3);
		sl.addNumbers(l.begin(), l.end());
		std::cout << sl.longestSpan() << std::endl; // 7 - (-2) = 9
	}
	std::cout << std::endl;

	std::cout << "---- Copy ctor/assignment ----" << std::endl;
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		Span copy(sp);
		Span assigned(1);
		assigned = sp;
		std::cout << "sp: " << sp.longestSpan() << std::endl; // 14
		std::cout << "copy: " << copy.longestSpan() << std::endl; // 14
		std::cout << "assigned: " << assigned.longestSpan() << std::endl; // 14
	}
	std::cout << std::endl;

	std::cout << "---- Large scale + INT_MIN/MAX overflow check ----" << std::endl;
	{
		Span big(10000);
		std::vector<int> vals;
		for (int i = 0; i < 9998; ++i) {
			vals.push_back((i));
		}
		vals.push_back(std::numeric_limits<int>::min());
		vals.push_back(std::numeric_limits<int>::max());
		big.addNumbers(vals.begin(), vals.end());
		std::cout << "shortest: " << big.shortestSpan() << std::endl; // 1
		std::cout << "longest: " << big.longestSpan() << std::endl; // intmax - intmin
	}

	return 0;
}