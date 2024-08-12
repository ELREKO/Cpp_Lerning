#include "Animal.hpp"

# ifndef DOG_HPP
# define DOG_HPP


class Dog : public Animal
{
	protected:
    	std::string setSpecialAnimalSound()const;
        
  	public:
		// Constructor 
		Dog();
		Dog(const Dog& copy);

		// Operater Overload
		Dog &operator=(const Dog &src);

		// Deconstructor 
		~Dog();
};

# endif