# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "../../lib/console_setting/color.h"

#define MAX_ITEMS 4

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[MAX_ITEMS];
	public:
		// Constructors
		Character(void);
		Character(std::string const &name);
		Character(Character const &copy);
		
		// Basic Operators 
		Character const	&operator=(Character const &copy);

		// Destructors
		~Character(void);

		// Getters & Setters 
		std::string const	&getName(void) const;
		void				setName(std::string const &name);

		// Main Member Functions 
		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
		int 			inInventory(AMateria *m);
};

#endif