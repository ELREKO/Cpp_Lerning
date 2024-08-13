#include "Animal.hpp"
#include "Brain.hpp"

# ifndef DOG_HPP
# define DOG_HPP


class Dog : public Animal
{
	private:
		Brain* _brain;
        
  	public:
		// Constructor 
		Dog();
		Dog(const Dog& copy);

		// Operater Overload
		Dog &operator=(const Dog &src);

		// Deconstructor 
		~Dog();

		// Members
		void makeSound() const;

		// Setter 
		void setIdea(const unsigned nbr, const std::string idea);

		// Getter
		void getAllIdeas();
		std::string getIdea(const unsigned int nbr);
};

# endif