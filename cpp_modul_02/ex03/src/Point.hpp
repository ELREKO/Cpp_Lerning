# ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y; 

	public:
		Point();
		Point(Fixed x, Fixed y);
		Point(const Point &rhs);
		Point& operator=(Point &rhs);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

# endif