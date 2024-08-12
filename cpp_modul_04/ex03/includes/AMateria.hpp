# ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		// Constructors
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
		
		// Basic Operators 
		AMateria const	&operator=(AMateria const &copy);

		// Destructors
		virtual ~AMateria(void) = 0;

		// Getters & Setters
		std::string const	&getType(void) const;

		// Main Member Functions
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;
};

#endif