#pragma once

#include <iostream>
#include <limits>
#include <set>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Span {
	private:
		std::multiset<int> _numbers;
		unsigned int _maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		void addNumber(int nb);

		size_t shortestSpan();
		size_t longestSpan();

		class ContainerFullException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		template <typename inputIterator>
		void addNumbers(inputIterator begin, inputIterator end) {
			for (; begin != end; ++begin) {
				addNumber(*begin);
			}
		}
};
