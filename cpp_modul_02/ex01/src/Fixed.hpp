# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _fixedPointNumber;
	static const int _fractionalBit = 8;

public:
	Fixed();
	Fixed(const int iNbr);
	Fixed(const float fNbr);
	Fixed(const Fixed &rhs);
	Fixed& operator=( const Fixed &rhs );
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);


# endif