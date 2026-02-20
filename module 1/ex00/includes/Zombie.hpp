#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#define str std::string

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Zombie {
	private:
		str _name;
	
	public:
		Zombie();
		Zombie(str inName);
		~Zombie();
		str		getName();
		void	setName(const str &name);
		void	announce( void );
};




#endif