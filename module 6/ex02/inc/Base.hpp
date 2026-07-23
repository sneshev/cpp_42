#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class A;
class B;
class C;

class Base {
	private:
		
	public:
		virtual ~Base();
		
		static Base* generate();
		static void  identify(Base* p);
		static void  identify(Base& p);
};
