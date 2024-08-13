#include "WrongAnimal.hpp"


# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP


class WrongCat : public WrongAnimal
{    
  	public:
		// Constructor 
		WrongCat();
		WrongCat(const WrongCat& copy);

		// Operater Overload
		WrongCat &operator=(const WrongCat &src);

		// Deconstructor 
		~WrongCat();
		void makeSound() const;
};

# endif