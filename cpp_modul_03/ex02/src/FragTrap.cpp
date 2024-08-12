# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	setMaxRepair(getHitPoints());
	std::cout 	<< BRIGHT_BACKGROUND_GREEN << BRIGHT_CYAN
				<< "Call Default Constucter FragTrap --> \"" << getName() << "\" called"
				<< RESET << std::endl;
	getStatus();
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout 	<< BRIGHT_BACKGROUND_GREEN << BRIGHT_CYAN
		 		<< "Use ScavTrap Copy Constructer FragTrap --> \"" << getName() << "\" called" 
				<< RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap (name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	setMaxRepair(getHitPoints());
	std::cout 	<< BRIGHT_BACKGROUND_GREEN << BRIGHT_CYAN
				<< "Call (string) Constructor FragTrap --> \"" << getName() << "\" called" 
				<< RESET << std::endl;
	getStatus();
}

FragTrap &FragTrap::operator=(const FragTrap& src) {
    ClapTrap::operator=(src);
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << BRIGHT_BACKGROUND_RED << BRIGHT_BLUE;
	std::cout << "Call Deconstucter FragTrap :"  << RESET << WHITE << " " << getName();
	std::cout << RESET << std::endl;	
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << getName() << " : You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}
