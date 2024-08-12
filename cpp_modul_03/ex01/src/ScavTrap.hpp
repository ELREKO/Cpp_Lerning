# include "../../ex00/src/ClapTrap.hpp"

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

class ScavTrap : virtual public ClapTrap 
{
	private: 
		bool _guardGate;

	protected: 
		bool getGuardGate();
		void setGuardGate(const bool sate);
		
	public :
		// Constucter
		ScavTrap();
		ScavTrap(const ScavTrap& copy);
		ScavTrap(std::string name);
		
		// Overloaded Operators
		ScavTrap& operator=(const ScavTrap& src);

		// Deconstructor
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();	
};

#endif