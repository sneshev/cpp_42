#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

class Animal {
	protected:
		std::string _type;
		Animal(std::string inType);
	
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;
};



#endif