# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	setMaxRepair(getHitPoints());
	setGuardGate(false);
	std::cout 	<< BACKGROUND_GREEN << WHITE
				<< "Call Default Constucter ScavTrap --> \"" << getName() << "\" called"
				<< RESET << std::endl;
	getStatus();
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	setGuardGate(copy._guardGate);
	std::cout 	<< BACKGROUND_GREEN << WHITE
		 		<< "Use ScavTrap Copy Constructer ScavTrap --> \"" << getName() << "\" called" 
				<< RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	setMaxRepair(getHitPoints());
	setGuardGate(false);
	std::cout 	<< BACKGROUND_GREEN << WHITE
				<< "Call (string) Constructer ScavTrap --> \"" << getName() << "\" called" 
				<< RESET << std::endl;
	getStatus();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) 
{
    ClapTrap::operator=(src);
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << BACKGROUND_RED;
	std::cout << "Call Constucter ScavTrap:"  << RESET << WHITE << " " << getName();
	std::cout << RESET << std::endl;	
}

bool ScavTrap::getGuardGate()
{return (this->_guardGate);}

void ScavTrap::setGuardGate(const bool state)
{this->_guardGate = state;}

void ScavTrap::attack(const std::string& target)
{
	std::cout << BACKGROUND_MAGENTA;
	if (getEneryPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " 
		<< target << " causing " << getAttackDamage() << " points of damage !" 
		<< RESET << std::endl; 
	}
	else if(getEneryPoints() <= 0)
	{
		std::cout <<  "ScavTrap " << getName() << "be able to attack " 
		<< &target << " becouse no energy points !" 
		<<  std::endl; 
	}
	else
		{
		std::cout  <<  "ScavTrap " <<  getName() << "be able to attack " 
		<< target << " becouse no hit points !" 
		<< std::endl; 
	}
	std::cout << RESET;
	setEnergyPoints(getEneryPoints() - 1);
	getStatus();
	return ;
}

void ScavTrap::guardGate()
{
	setGuardGate(true);
	std::cout 	<< BACKGROUND_YELLOW
				<< "ScavTrap " << getName() << " are in keeper mode" 
				<< RESET << std::endl;  
}
