#include "includes/Base.hpp"

int main (void)
{
    int max_class = 2;
    Base* test_class[max_class];

    for (int i = 0 ; i < max_class; i++)
    {
        std::cout << std::endl << std::endl << "------------------------------" << std::endl << std::endl;
        std::cout << "Class Modul"<< i << " Generate " << std::endl;
        test_class[i] = generate();
        identify(test_class[i]);
        identify(*test_class[i]); 
    }
    for (int i = 0 ; i < max_class; i++)
    {
        delete test_class[i];
    }
}