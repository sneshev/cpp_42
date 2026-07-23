#ifndef ARRAY_HPP
# include "Array.hpp"
#endif

template <typename T>
Array<T>::Array()
	: _elements(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	:  _elements(NULL), _size(n) 
{
	if (n > 0) {
		_elements = new T[n]();
	}
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		T* newElements = new T[other._size]();
		for (unsigned int i = 0; i < _size; i++) {
			newElements[i] = other._elements[i];
		}
		delete[] _elements;
		_elements = newElements;
		_size = other._size;

	}
	return *this;
}
