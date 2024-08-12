# include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber (0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	//*this = rhs;
	return ;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointNumber = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
	return;
}
