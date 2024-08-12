#include "include/Bsp_main.hpp"
/*
	Example for TRUE;
	a = (0, 0), b = (10, 30), c = (20, 0), p(10, 15) -- > true 

	Explanation:
				B(10,30)
				/ \
		       /   \
			  /     \
			 /   P   \      
			/         \
	A(0,0) ----------- C(20,0)

	Example for FALSE;
	a = (0, 0), b = (10, 30), c = (20, 0), p(30, 15) -- > False 

	Explanation:
				B(10,30)
				/ \
		       /   \
			  /     \
			 /   P   \      
			/         \
	A(0,0) ----------- C(20,0) 
*/

int main ( void )
{
	Point a = Point(0,0);
	Point b = Point(10,30);
	Point c = Point(20,0);
	//Point point = Point(10,15); //--> true 
	Point point = Point(30,15); //--> fals 

    if (bsp(a,b,c,point)) {
        std::cout << "Point is in the triangle" << std::endl;
    } else {
        std::cout << "Point is NOT in the triangle" << std::endl;
    }
    return 0;




}