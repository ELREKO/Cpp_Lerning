#include "src/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	// std::cout << Fixed::min( a, b ) << std::endl;
	// std::cout << a << std::endl;
	// std::cout << --a<< std::endl;
	// std::cout << --a << std::endl;
	// std::cout << --a << std::endl;

	// a = Fixed(10);
	// Fixed c(10.111f);
	// std::cout << a << std::endl;
	// std::cout << "c ist: " << c << std::endl;
	// Fixed d = (a - c);
	// std::cout << d << std::endl;
	return 0;
}