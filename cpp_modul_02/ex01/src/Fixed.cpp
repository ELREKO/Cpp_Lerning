# include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber (0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int iNbr)
{
	int iTmp;
	iTmp = iNbr;
	while (iTmp < -9999999 || iTmp > 9999999)
	{
		iTmp /= 10;
	}
	this->_fixedPointNumber = iTmp << _fractionalBit;
	std::cout << "Int constructor called" << std::endl;
	return ;
}


Fixed::Fixed (const float fNbr) : _fixedPointNumber(roundf(fNbr * (1 << _fractionalBit)))
{
	std::cout << "float constructor called" << std::endl;
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

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointNumber / (float)(1 << this->_fractionalBit));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointNumber >> this->_fractionalBit);
}

std::ostream &  operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o); 
}
