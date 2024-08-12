#include "includes/Zombie_main.hpp"

int main(void)
{
	std::cout << std::endl;
	Zombie *z = newZombie("evaluator");
	std::cout << std::endl;
	randomChump("BOB");
	std::cout << std::endl;
	randomChump("MAX");
	std::cout << std::endl;
	z->announce();
	z->announce();
	delete z;
	return 0; 
}