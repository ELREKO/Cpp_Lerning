# ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "../../lib/console_setting/color.h"
#define MAX_LEARN_INVENRORY 4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_learnInventory[MAX_LEARN_INVENRORY];

	public:
		// Constructors
		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);

		// Basic Operators 
		MateriaSource const	&operator=(MateriaSource const &copy);

		// Destructors 
		~MateriaSource(void);

		// Main Member Functions 
		virtual void		learnMateria(AMateria *materia);
		virtual AMateria*	createMateria(std::string const &type);
		int 				inLearnInventory(AMateria *materia);
};

#endif