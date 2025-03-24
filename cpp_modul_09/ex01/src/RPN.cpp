#include "../include/RPN.hpp"

template <typename T>
void displayStack(std::stack<T> stack) {

    std::cout << "Stack-Inhalt LIFO ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

std::string getColorCode(printColor color) {
    std::ostringstream oss;
    oss << "\033[" << color << "m";
    return oss.str();
}


// ------------------------------------------ Const and Deconstr ---------------------------
RPN::RPN()
{}



RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
	{
		this->_nbr_stack = src._nbr_stack;
	}
	return (*this);
}

RPN::~RPN()
{
    while (!this->_nbr_stack.empty())
        this->_nbr_stack.pop();
}

//---------------------------------------------- public members ------------------------


double RPN::pop_nbr()
{
    double nbr = _nbr_stack.top();
    _nbr_stack.pop();
    return nbr;
}


int RPN::Calculate(std::string input)
{
    int temp; 
    for (size_t i=0; i < input.size(); i++)
    {
        char chr = input[i];
        if (isspace(chr))
            continue;
        else if (isdigit(chr))
        {
            int num = chr - '0';
            this->_nbr_stack.push(num);
        }        
        else if (chr == '/' && this->_nbr_stack.size() >= 2)
        {
            temp = pop_nbr();
            if (temp == 0)
            {
                std::cerr << getColorCode (RED) << "Division 0 not allowed!" << getColorCode(RESET);  
                return (1);
            }
            this->_nbr_stack.push(pop_nbr() / temp);
        }
        else if (chr == '-' && this->_nbr_stack.size() >= 2)
        {
            temp = pop_nbr();
            this->_nbr_stack.push(pop_nbr() - temp);
        }
        else if (chr == '+' && this->_nbr_stack.size() >= 2)
            this->_nbr_stack.push(pop_nbr() + pop_nbr());
        else if (chr == '*' && this->_nbr_stack.size() >= 2)
            this->_nbr_stack.push(pop_nbr() * pop_nbr());
        else
        {
            std::cout << "Invalid input." << std::endl; 
            return (1);
        }
    }

    if (this->_nbr_stack.size() == 1)
    {
        std::cout << "Result: " << this->_nbr_stack.top() << std::endl;
        return (0);
    }
    else
    {
        std::cerr << getColorCode(RED) << "Invalid input." << getColorCode(RESET) << std::endl;
        return (1);
    }
    return 0;
}
