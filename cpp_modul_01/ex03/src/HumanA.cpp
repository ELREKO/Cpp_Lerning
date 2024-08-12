#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _Wepoan(weapon)
{
	std::cout << std::endl;
	std::cout << "Creating Human A named [" << this->_name << "] and a Weapon of: " << this->_Wepoan.getType(); 
	std::cout << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destroying Human A named [" << this->_name << "]";
	std::cout << std::endl;
}
void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_Wepoan.getType();
	std::cout << std::endl;
}
void HumanA::setWeapon(Weapon &Weapon)
{
	this->_Wepoan = (Weapon);
}