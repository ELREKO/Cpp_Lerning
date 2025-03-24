# ifndef BASE_HPP
# define BASE_HPP

# include "Generally_Header.hpp"

class A;
class B;
class C;

class Base
{
// private:
//     Base();
//     Base(const Base &copy);
//     Base &operator=(const Base &src);
    
    
public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif