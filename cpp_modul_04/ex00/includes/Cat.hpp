#include "Animal.hpp"


# ifndef CAT_HPP
# define CAT_HPP


class Cat : public Animal
{ 
  	public:
		// Constructor 
		Cat();
		Cat(const Cat& copy);

		// Operater Overload
		Cat &operator=(const Cat &src);

		// Deconstructor 
		~Cat();

		// Members
		void makeSound() const; 
};

# endif