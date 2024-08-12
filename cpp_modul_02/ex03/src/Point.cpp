#include "Point.hpp"

Point::Point() : _x(), _y()
{
	//std::cout << "Use default Constructor Point!" << std::endl;
	return ;
}
Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{
	//std::cout << "Use Parameter Constructor Point!" << std::endl;
	return ;
}

Point::Point(const Point &rhs) : _x(rhs._x) , _y(rhs._y)
{
	//std::cout << "Use Copy Constructor Point!" << std::endl;
	return ;
}
Point& Point::operator=(Point &rhs)
{
	if (this != &rhs)
	{
		(Fixed) this->_x = rhs.getX();
		(Fixed) this->_y = rhs.getY();
	}
	return *this; 
}

Point::~Point()
{
	//std::cout << "Use Deconstructor Point!" << std::endl;
	return ;
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}

