#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

template <typename T>
class Array {
	private:
		T*			 _elements;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;

		class OutOfBoundsException : public std::excetion {
			public:
				virtual const char* what() const noexcept;
		};
		
};

# include "Array.tpp"

#endif