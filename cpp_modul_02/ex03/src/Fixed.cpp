# include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber (0)
{
	//std::cout << "Default constructor called" << std::endl;
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
	//std::cout << "Int constructor called" << std::endl;
	return ;
}


Fixed::Fixed (const float fNbr) : _fixedPointNumber(roundf(fNbr * (1 << _fractionalBit)))
{
	//std::cout << "float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &rhs)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	//*this = rhs;
	return ;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointNumber = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

// --------------------- comparison operators --------------------
bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixedPointNumber < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixedPointNumber > rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPointNumber <= rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPointNumber >= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixedPointNumber == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixedPointNumber != rhs.getRawBits());
}

// --------------------- arithmetic operators ---------------------

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}


// -------------  increment/decrement --------------------

Fixed& Fixed::operator++(void)
{
	++this->_fixedPointNumber;
	return (*this); 
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp._fixedPointNumber = this->_fixedPointNumber++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	--this->_fixedPointNumber;
	return (*this); 
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp._fixedPointNumber = this->_fixedPointNumber--;
	return (tmp);
}

// -------------------------- min / max -----------------------

Fixed& Fixed::min (Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed& Fixed::min (const Fixed &a, const Fixed &b)
{	
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed& Fixed::max (Fixed &a, Fixed &b)
{	
	if (b.getRawBits() > a.getRawBits())
		return b;
	return a;
}

const Fixed& Fixed::max (const Fixed &a, const Fixed &b)
{	
	if (b.getRawBits() > a.getRawBits())
		return b;
	return a;
}

// ----- Value Set and get ---------

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
	return;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumber);
}

//  ---- convert

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointNumber / (float)(1 << this->_fractionalBit));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointNumber >> this->_fractionalBit);
}


// << overload 

std::ostream &  operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o); 
}
