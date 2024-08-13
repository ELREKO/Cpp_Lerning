#include "AAnimal.hpp"
#include "Brain.hpp"


# ifndef CAT_HPP
# define CAT_HPP


class Cat : public AAnimal
{
	private:
		Brain* _brain;
    	
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

		// Setter 
		void setIdea(const unsigned nbr, const std::string idea);

		// Getter
		void getAllIdeas();
		std::string getIdea(const unsigned int nbr);
};

# endif