#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAXTHOUGHTS 100


class Brain {
	private:
		std::string _ideas[MAXTHOUGHTS];

	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		
		Brain& operator=(const Brain& other);
};




#endif