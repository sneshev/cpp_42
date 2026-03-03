#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;

	public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	void	makeSound() const override;

	std::string	getIdea(unsigned int index);
	int			setIdea(unsigned int index, const std::string inIdea);
};

#endif
