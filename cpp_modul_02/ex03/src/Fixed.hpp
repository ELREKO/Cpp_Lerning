# ifndef FIXED_HPP
# define FIXED_HPP

# include "../include/Bsp_ext_funct.hpp"

class Fixed
{
private:
	int _fixedPointNumber;
	static const int _fractionalBit = 8;

public:
	// -- constructor - deconsturctor --
	Fixed();
	Fixed(const int iNbr);
	Fixed(const float fNbr);
	Fixed(const Fixed &rhs);
	~Fixed();

	Fixed& operator=(const Fixed &rhs);

	// -- comparison operators --
	
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	// -- arithmetic operators -- 
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	// -- increment/decrement -- 
	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	// -- min / max --
	static Fixed& min (Fixed &a, Fixed &b); 
	static const Fixed& min (const Fixed &a, const Fixed &b); 
	static Fixed& max (Fixed &a, Fixed &b); 
	static const Fixed& max (const Fixed &a, const Fixed &b); 

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);


# endif