#ifndef HARL_H
#define HARL_H

#include <iostream>
#define str std::string

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#define MAXFUN 4

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		~Harl();
		void complain( std::string level );
		typedef void (Harl::*fun)(void);
};

#endif