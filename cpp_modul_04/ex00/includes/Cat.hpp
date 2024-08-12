#include "Animal.hpp"


# ifndef CAT_HPP
# define CAT_HPP


class Cat : public Animal
{
	protected:
    	std::string setSpecialAnimalSound()const;
        
  	public:
		// Constructor 
		Cat();
		Cat(const Cat& copy);

		// Operater Overload
		Cat &operator=(const Cat &src);

		// Deconstructor 
		~Cat();
};

# endif