# ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include "../../lib/console_setting/color.h"

class Ice: public AMateria
{
	public:
		// Constructors
		Ice(void);
		Ice(Ice const &copy);
		
		// Basic Operators 
		Ice const	&operator=(Ice const &copy);

		// Destructors
		~Ice(void);

		// Main Member Functions 
		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};

#endif