#pragma once

#include "Base.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class B : public Base {
	private:
		
	public:
		B();
		B(const B& other);
		B& operator=(const B& other);
		~B();
		
};
