#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)  : _type(weapon)
{}

Weapon::~Weapon()
{}

const std::string Weapon::getType(void)
{
	return (this->_type);
}
void Weapon::setType(std::string weapon)
{
	this->_type = weapon;
	 
}