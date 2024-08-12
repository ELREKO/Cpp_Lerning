#include <string>
#include <iostream>
#include "../../lib/console_setting/color.h"



# ifndef AANIMAL_HPP
# define AANIMAL_HPP


class AAnimal
{
	protected:
		std::string _type;
    virtual std::string setSpecialAnimalSound()const = 0;
        
  public:
    // Constructor 
    AAnimal();
    AAnimal(const AAnimal& copy);
    AAnimal(const std::string type);

    // Operater Overload
    AAnimal &operator=(const AAnimal &src);

    // Deconstructor 
    virtual ~AAnimal() = 0;

    // Getter
    std::string getType(void)const;

    // Setter
    void setType(const std::string type);

    // requested members
    void makeSound() const; 
};

# endif