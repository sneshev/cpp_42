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
	:  _elements(NULL), _size(0) 
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		T* newElements = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++) {
			newElements[i] = other._elements[i];
		}

		delete[] _elements;
		_elements = newElements;
		_size = other._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _elements;
}


template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index < _size) {
		return (_elements[index]);
	}
	throw OutOfBoundsException();
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index < _size) {
		return (_elements[index]);
	}
	throw OutOfBoundsException();
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const noexcept {
	return ("Out of bounds");
}