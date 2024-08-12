# ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"
#include "../../lib/console_setting/color.h"

class Cure: public AMateria
{
	public:
		// Constructors
		Cure(void);
		Cure(Cure const &copy);
		
		// Basic Operators 
		Cure const	&operator=(Cure const &copy);

		// Destructors
		~Cure(void);
		
		// Main Member Functions
		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};

#endif