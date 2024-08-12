#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << std::endl;
	std::cout << "Creating Human A named [" << this->_name << "] and a Weapon of: ";  //<< this->_Wepoan->getType(); 
	std::cout << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destroying Human A named [" << this->_name << "]";
	std::cout << std::endl;
}
void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_Wepoan->getType();
	std::cout << std::endl;
}
void HumanB::setWeapon(Weapon &Weapon)
{
	this->_Wepoan = (&Weapon);
}