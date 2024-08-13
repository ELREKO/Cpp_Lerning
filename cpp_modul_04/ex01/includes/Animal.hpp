#include <string>
#include <iostream>
#include "../../lib/console_setting/includes/FontColorTerminal.hpp"


# ifndef ANIMAL_HPP
# define ANIMAL_HPP


class Animal
{
	protected:
		std::string _type;
        
  public:
    // Constructor 
    Animal();
    Animal(const Animal& copy);
    Animal(const std::string type);

    // Operater Overload
    Animal &operator=(const Animal &src);

    // Deconstructor 
    virtual ~Animal();

    // Getter
    std::string getType(void)const;

    // Setter
    void setType(const std::string type);

    // requested members
    virtual void makeSound() const; 
};

# endif