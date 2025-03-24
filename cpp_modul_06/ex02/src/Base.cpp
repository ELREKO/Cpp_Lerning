#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base() {} 

Base * generate(void)
{
    std::srand(std::time(NULL)); 
    int randomNbr = rand() % 3;
    if (randomNbr == 0)
        return new A;
    else if (randomNbr == 1)
        return new B;
    else 
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Given POINTER Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Given POINTER Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Given POINTER Class C" << std::endl;
    else 
        std::cout << "ERROR: No Class A, B or C given" << std::endl;
}

void identify(Base& p)
{
    try
    {  
        A cl_a = dynamic_cast<A&>(p);
        std::cout << "Given REFERENCE Class A" << std::endl;
        return;
    } 
    catch (std::exception &e) {}
    
    try
    {  
        B cl_b = dynamic_cast<B&>(p);
        std::cout << "Given REFERENCE Class B" << std::endl;
        return;
    } 
    catch (std::exception &e) {}
    
    try
    {  
        C cl_c = dynamic_cast<C&>(p);
        std::cout << "Given REFERENCE Class C" << std::endl;
        return;
    } 
    catch (std::exception &e) {}
    std::cout << "ERROR: No Class A, B or C given" << std::endl;
}
