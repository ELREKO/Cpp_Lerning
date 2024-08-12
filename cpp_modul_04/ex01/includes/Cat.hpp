#include "Animal.hpp"
#include "Brain.hpp"


# ifndef CAT_HPP
# define CAT_HPP


class Cat : public Animal
{
	private:
		Brain* _brain;

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

		// Setter 
		void setIdea(const unsigned nbr, const std::string idea);

		// Getter
		void getAllIdeas();
		std::string getIdea(const unsigned int nbr);




		// other member funciton
		void checkBarinAllocation();

};

# endif