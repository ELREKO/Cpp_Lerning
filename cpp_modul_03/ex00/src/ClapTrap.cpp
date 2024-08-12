#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no Name"), _hit_points(10), _energy_points(10), _attack_damage(0), _max_repair(_hit_points)
{
	std::cout 	<< GREEN
				<< "Call Default Constucter ClapTrap --> \"" << getName() << "\" called"
				<< RESET << std::endl;
	getStatus();
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout 	<< GREEN 
				<< "Call Copy Constructer ClapTrap --> \"" << getName() << "\" called" 
				<< RESET << std::endl;
	setAllMainAttributsCopy(copy);
	std::cout << "copy form " << std::endl;
	copy.getStatus();
	std::cout << "copy to " << std::endl;
	getStatus();
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10),  _attack_damage(0), _max_repair(_hit_points)
{
	std::cout 	<< GREEN 
				<< "Call (string) Constructer ClapTrap --> \"" << getName() << "\" called" 
				<< RESET << std::endl;
	getStatus();
	
}

ClapTrap&ClapTrap::operator=(const ClapTrap& src)
{
	if (this != &src)
	{
		std::cout << "Use ClapTrap Assignation operator called" << std::endl;
		std::cout << "Parameter befor copy" << std::endl;
		src.getStatus("Copy from --> ");
		this->getStatus("Copy to -->");
		setAllMainAttributsCopy(src);
		std::cout << "Parameter After Copy" << std::endl;
		getStatus("Copy --> ");
		src.getStatus("SRC --> ");
	}

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Call Deconstructer with name : " << BLUE << getName() << " !" << RESET << std::endl;
}
/*
ClapTrap::ClapTrap(ClapTrap&& moveconst) noexcept
    : _name(std::move(moveconst._name)), _hit_points(moveconst._hit_points), _energy_points(moveconst._energy_points), _attack_damage(moveconst._attack_damage)
{
	std::cout << "Call Move Constructer" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap&& src) noexcept
{
	std::cout << "ClapTrap Move Assignation operator called" << std::endl;
    if (this != &src)
    {
        _name = std::move(src._name);
        _hit_points = src._hit_points;
        _energy_points = src._energy_points;
        _attack_damage = src._attack_damage;
    }
    return *this;
}
*/

// Getter 
std::string ClapTrap::getName() const
{return (this->_name);}
unsigned int ClapTrap::getHitPoints() const
{return (this->_hit_points);}
unsigned int ClapTrap::getEneryPoints() const
{return (this->_energy_points);}
unsigned int ClapTrap::getAttackDamage() const
{return (this->_attack_damage);}
unsigned int ClapTrap::getMaxRepair() const
{return (this->_max_repair);}

//Setter
void ClapTrap::setAllMainAttributsCopy(const ClapTrap& copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEneryPoints());
	setAttackDamage(copy.getAttackDamage());	
}

void ClapTrap::setName(std::string name)
{ this->_name = name;}
void ClapTrap::setHitPoints(const unsigned int hit_ponts)
{ this->_hit_points = hit_ponts;}
void ClapTrap::setEnergyPoints(const unsigned int energy_Points)
{ this->_energy_points = energy_Points;}
void ClapTrap::setAttackDamage(const unsigned int attack_damage)
{ this->_attack_damage = attack_damage;}
void ClapTrap::setMaxRepair(const unsigned int max_repair)
{ this->_max_repair = max_repair;}

void ClapTrap::attack(const std::string& target)
{
	std::cout << BOLD;
	if (getEneryPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks " 
		<< target << " causing " << getAttackDamage() << " points of damage !" 
		<< RESET << std::endl; 
	}
	else if(getEneryPoints() <= 0)
	{
		std::cout <<  "ClapTrap " << getName() << "be able to attack " 
		<< &target << " becouse no energy points !" 
		<<  std::endl; 
	}
	else
		{
		std::cout  <<  "ClapTrap " <<  getName() << "be able to attack " 
		<< target << " becouse no hit points !" 
		<< std::endl; 
	}
	std::cout << RESET;
	setEnergyPoints(getEneryPoints() - 1);
	getStatus();
	return ;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BACKGROUND_RED;
	if(getHitPoints() > amount)
	{
		setHitPoints(getHitPoints() - amount);
	}
	else if( getHitPoints() > 0)
	{
		setHitPoints(0);
	}
	if (getHitPoints() == 0)
	{
		std::cout << BLACK <<"Trap " << getName()
		<< " is already dead, stop beating it.";
	}
	if (getHitPoints() > 0)
	{
		std::cout << "Trap " << getName() << " lose " << amount << " hit points !";
	}
	std::cout << RESET << std::endl; 
	getStatus();
	return ;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	//this->_max_repair = 10;
	std::cout << UNDERLINE;
	if(getHitPoints() > 0 && getHitPoints() < getMaxRepair() && getEneryPoints() > 0)
	{
		if ((getHitPoints() + amount) > getMaxRepair())
			setHitPoints(10);
		else
			setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEneryPoints() - 1);
		std::cout 	<< "Trap " << getName() << " Repaird !" << std::endl;
	}
	else if(getEneryPoints() == 0)
	{
		std::cout 	<< "Trap " << getName() << " couldn't repaid, cousing "
					<< "actuall energy Points " << getEneryPoints()
					<< std::endl; 
	}
	else if(getHitPoints() == 0)
		std::cout 	<< "Trap " << getName() << " couldn't repaid, cousing "
					<< "actuall hit points " << getHitPoints()
					<< std::endl; 
	else
	{
		std::cout 	<< "Trap " << getName() << " couldn't repaid, cousing "
					<< "actuall hit points " << getHitPoints()
					<< " max hit point is 10"  << std::endl; 
	}
	std::cout << RESET;
	getStatus();
}

void ClapTrap::getStatus(const std::string& prefix) const
{
	std::cout 	<< prefix << YELLOW 
				<< "Status " << getName() << " :" 
				<< BLUE << "hit points = "
				<< WHITE << "|" << getHitPoints() << "|" 
				<< BLUE << " --> energy points = "
				<< WHITE << "|" << getEneryPoints() << "|"  
				<< BLUE << " --> actuall damage attack = " 
				<< WHITE << "|" << getAttackDamage() << "|" 
				<< RESET << std::endl;
}
