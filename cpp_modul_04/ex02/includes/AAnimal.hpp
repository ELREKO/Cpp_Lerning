#include <string>
#include <iostream>
#include "../../lib/console_setting/includes/FontColorTerminal.hpp"


# ifndef ANIMAL_HPP
# define ANIMAL_HPP


class AAnimal
{
	protected:
		std::string _type;
        
  public:
    // Constructor 
    AAnimal();
    AAnimal(const AAnimal& copy);
    AAnimal(const std::string type);

    // Operater Overload
    AAnimal &operator=(const AAnimal &src);

    // Deconstructor 
    virtual ~AAnimal();

    // Getter
    std::string getType(void)const;

    // Setter
    void setType(const std::string type);

    // requested members
    virtual void makeSound() const = 0; // pure virtual class 
};

# endif