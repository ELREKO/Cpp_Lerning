#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "no Name";
    setEnergyPoints(50); // From ScavTrap
    std::cout << BRIGHT_BACKGROUND_WHITE << BLACK 
              << "DiamondTrap Default Constructor " << getName() << " called." 
              << RESET << std::endl;
    getStatus();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap")
{
    this->_name = name;
    setEnergyPoints(50); // From ScavTrap
    std::cout << BRIGHT_BACKGROUND_WHITE << BLACK 
              << "Call (string) Constructor DiamondTrap --> " << _name << " called" 
              << RESET << std::endl;
    getStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
    std::cout << BRIGHT_BACKGROUND_GREEN << BRIGHT_CYAN
              << "Use DiamondTrap Copy Constructor " << _name << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    ClapTrap::operator=(src);
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << BRIGHT_BACKGROUND_BLACK << WHITE;
    std::cout << "Call Destructor DiamondTrap:" << RESET << BLUE << " " << _name;
    std::cout << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "Hello, I am a DiamondTrap named " << this->_name <<
    " and I am originated from the ClapTrap named " << ClapTrap::getName() << "." <<
    std::endl;
}
