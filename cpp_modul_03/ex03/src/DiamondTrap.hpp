#include  "../../ex00/src/ClapTrap.hpp"
# include "../../ex01/src/ScavTrap.hpp"
# include "../../ex02/src/FragTrap.hpp"


#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

class DiamondTrap :  public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public :
		//Constucter
		DiamondTrap();
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap(std::string name);
		
		// Overloaded Operators
		DiamondTrap& operator=(const DiamondTrap& src);

		// Deconstructor
		virtual ~DiamondTrap();

		// Function 
		void attack(const std::string &target);
		void whoAmI(void);
};

#endif