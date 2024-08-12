#include "Animal.hpp"

# ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP


class WrongAnimal
{
	protected:
		std::string _type;
    	std::string setSpecialWrongAnimalSound()const;
        
  public:
    // Constructor 
    WrongAnimal();
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal(const std::string type);

    // Operater Overload
    WrongAnimal &operator=(const WrongAnimal &src);

    // Deconstructor 
    virtual ~WrongAnimal();

    // Getter
    std::string getType(void)const;

    // Setter
    void setType(const std::string type);

    // requested members
    void makeSound() const; 
};

# endif