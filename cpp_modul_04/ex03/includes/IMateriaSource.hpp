# ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		// Constructors
		IMateriaSource(void);
		IMateriaSource(IMateriaSource const &copy);
		
		// Basic Operators 
		IMateriaSource const	&operator=(IMateriaSource const &copy);

		// Destructors 
 		virtual ~IMateriaSource() = 0;
		
		// Main Member Functions 
		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif