#include "template.hpp"

templates::templates() : _name("no name"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\033[32mCall Constructer with \033[34m" << getName() << " !\033[0m" << std::endl;
}

templates::templates(const templates& copy)
{
	std::cout << "\033[32mCall Copy Constructer\033[0m" << std::endl;
	*this = copy;
}

templates::templates(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\033[32mCall Constructer with given name: \033[34m" << getName() << " !\033[0m" << std::endl;
}

templates&templates::operator=(const templates& src)
{
	if (this != &src)
	{
		std::cout << "templates Assignation operator called" << std::endl;
		this->_name 			= src._name;
		this->_hit_points 		= src._hit_points;
		this->_energy_points 	= src._energy_points;
		this->_attack_damage	= src._attack_damage;
		return *this;
	}
}

templates::~templates()
{
	std::cout << "\033[31mCall Deconstructer with name :\033[34m" << getName() << " !\033[0m" << std::endl;
}

templates::templates(templates&& moveconst) noexcept
    : _name(std::move(moveconst._name)), _hit_points(moveconst._hit_points), _energy_points(moveconst._energy_points), _attack_damage(moveconst._attack_damage)
{
	std::cout << "Call Move Constructer" << std::endl;
}

templates& templates::operator=(templates&& src) noexcept
{
	std::cout << "templates Move Assignation operator called" << std::endl;
    if (this != &src)
    {
        _name = std::move(src._name);
        _hit_points = src._hit_points;
        _energy_points = src._energy_points;
        _attack_damage = src._attack_damage;
    }
    return *this;
}

// Getter 
std::string templates::getName()
{return (this->_name);}
unsigned int templates::getHitPoints()
{return (this->_hit_points);}
unsigned int templates::getEneryPoints()
{return (this->_energy_points);}
unsigned int templates::getAttackDamage()
{return (this->_attack_damage);}

//Setter
void templates::setName(std::string name)
{ this->_name = name;}
void templates::setHitPoints(unsigned int hit_ponts)
{ this->_hit_points = hit_ponts;}
void templates::setEnergyPoints(unsigned int energy_Points)
{ this->_energy_points = energy_Points;}
void templates::setAttackDamage(unsigned int attack_damage)
{ this->_attack_damage = attack_damage;}


