#include "WrongAnimal.hpp"


# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP


class WrongCat : public WrongAnimal
{
	protected:
    	std::string setSpecialAnimalSound()const;
        
  	public:
		// Constructor 
		WrongCat();
		WrongCat(const WrongCat& copy);

		// Operater Overload
		WrongCat &operator=(const WrongCat &src);

		// Deconstructor 
		~WrongCat();
};

# endif