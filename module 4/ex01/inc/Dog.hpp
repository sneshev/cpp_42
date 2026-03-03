#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;

	public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void	makeSound() const override;

	std::string	getIdea(unsigned int index);
	int			setIdea(unsigned int index, const std::string inIdea);

	
};


#endif