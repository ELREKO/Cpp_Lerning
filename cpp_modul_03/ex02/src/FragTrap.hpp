# include "../../ex00/src/ClapTrap.hpp"

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

class FragTrap : virtual public ClapTrap 
{	
	public :
		// Constucter
		FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap(std::string name);
		
		// Overloaded Operators
		FragTrap& operator=(const FragTrap& src);

		// Deconstructor
		~FragTrap();
		void highFiveGuys(void);
};

#endif