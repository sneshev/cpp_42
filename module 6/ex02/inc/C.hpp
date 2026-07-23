#pragma once

#include "Base.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class C : public Base {
	private:
		
	public:
		C();
		C(const C& other);
		C& operator=(const C& other);
		~C();
	
};
