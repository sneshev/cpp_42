#pragma once
#include <iostream>
#include <cstddef> //size_t

template <typename T>
void iter(const T array[], size_t arraySize, void (*f)(const T&)) {
	for (size_t i = 0; i < arraySize; i++) {
		f(array[i]);
	}
}


template <typename T>
void iter(T array[], size_t arraySize, void (*f)(T&)) {
	for (size_t i = 0; i < arraySize; i++) {
		f(array[i]);
	}
}



template <typename T>
void print(const T& element) {	
	std::cout << element << " ";
}
