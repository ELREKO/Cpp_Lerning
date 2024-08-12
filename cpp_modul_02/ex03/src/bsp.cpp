#include "../include/Bsp_main.hpp"
// Calculate if a point in a triangel 
// Calculate for Baryzentrischen Koordinaten

typedef struct triangle
{
	Fixed a_x;
	Fixed a_y;
	Fixed b_x;
	Fixed b_y;
	Fixed c_x;
	Fixed c_y;
	Fixed p_x;
	Fixed p_y;
} t_triangle;

t_triangle *init_point(Point const a, Point b, Point c, Point point)
{
	t_triangle *triangle = new t_triangle;

	triangle->a_x = a.getX();
	triangle->a_y = a.getY();

	triangle->b_x = b.getX();
	triangle->b_y = b.getY();

	triangle->c_x = c.getX();
	triangle->c_y = c.getY();

	triangle->p_x = point.getX();
	triangle->p_y = point.getY();

	return (triangle);
}


// α = ((y - y_c)(x_b - x_c) - (x - x_c)(y_b - y_c)) / ((y_a - y_c)(x_b - x_c) - (x_a - x_c)(y_b - y_c))
static Fixed alpha (t_triangle *t)
{
	Fixed ret;
	ret = 	(
				(t->p_y - t->c_y)*(t->b_x - t->c_x) -
				(t->p_x - t->c_x)*(t->b_y - t->c_y)
			) /
			(
				(t->a_y - t->c_y)*(t->b_x - t->c_x) -
				(t->a_x - t->c_x)*(t->b_y - t->c_y)
			);
	std::cout<<ret.getRawBits()<<std::endl;
	return (ret);
}

//β = 	((y - y_a)(x_c - x_a) - (x - x_a)(y_c - y_a)) / ((y_b - y_a)(x_c - x_a) - (x_b - x_a)(y_c - y_a))
static Fixed beta (t_triangle *t)
{
	Fixed ret;
	ret =	(
				(t->p_y - t->a_y)*(t->c_x - t->a_x) - 
				(t->p_x - t->a_x)*(t->c_y - t->a_y) 
			) / 
			(
				(t->b_y - t->a_y)*(t->c_x - t->a_x) -
				(t->b_x - t->a_x)*(t->c_y - t->a_y)
			);
	std::cout<<ret.getRawBits()<<std::endl;
	return (ret);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    t_triangle *triangle = init_point(a, b, c, point);
    Fixed aa = alpha(triangle);
    Fixed bb = beta(triangle);
    if (aa >= 0 && bb >= 0 && (aa + bb) <= Fixed(1.0f))
        return true;
    return false;
}