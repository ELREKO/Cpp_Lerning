#include "src/DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond1;
	DiamondTrap diamond2("Max");
	DiamondTrap diamond3(diamond2);

	std::cout << std::endl << "---------------------------------" << std::endl;
	diamond1.attack("Max");
	diamond2.takeDamage(20);

	std::cout << std::endl << "---------------------------------" << std::endl;
	diamond1.attack("Max");
	diamond2.takeDamage(20);
	diamond2.beRepaired(5);

	std::cout << std::endl << "---------------------------------" << std::endl;
	diamond2.attack("no Name");
	diamond1.takeDamage(100);

	std::cout << std::endl << "---------------------------------" << std::endl;
	diamond2.attack("no name");
	diamond1.takeDamage(5);
	diamond1.beRepaired(10); 

    std::cout << std::endl << "---------------------------------" << std::endl;
	diamond1 = diamond2; 

	std::cout << std::endl << "---------------------------------" << std::endl;
	diamond2.whoAmI();
}
