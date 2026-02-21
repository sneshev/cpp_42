#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Fixed {
	private:
		int 				_fixed;
		static const int	_bits;

	public:
		Fixed();
		Fixed(const Fixed& fx);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif