#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int i) {
	return std::find(container.begin(), container.end(), i);
}