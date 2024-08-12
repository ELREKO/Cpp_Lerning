#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Creat a Zombie, with the name: " << this->_name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " died!" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}