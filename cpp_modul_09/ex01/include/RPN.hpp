#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

enum printColor {
    RED = 31,   
    GREEN = 32,  
    YELLOW = 33,
    BLUE = 34,  
	MAGENTA = 35,
	CYAN = 36, 
	GTAY = 30,
	WHITE = 37,
    RESET = 0  
};


class RPN
{
    private:
        std::stack <double> _nbr_stack;
    
    protected:
        double pop_nbr();

    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &src);
        ~RPN();

        int Calculate(std::string input);
};

std::string getColorCode(printColor color);
#endif