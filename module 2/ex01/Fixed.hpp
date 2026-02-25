#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#include <cmath>

class Fixed {
	private:
		int 				_value;
		static const int	_fractionalBitAmount;

	public:
		Fixed();
		Fixed(int const i);
		Fixed(float const fl);
		Fixed(const Fixed& fx);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed);

#endif