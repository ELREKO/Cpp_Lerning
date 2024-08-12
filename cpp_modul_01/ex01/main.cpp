#include "includes/Zombie_main.hpp"

int main(void)
{
	int hordSize = 20;
	Zombie *zHorde = zombieHorde(hordSize, "Max");
	for (int i = 0; i < hordSize; i++)
	{
		zHorde[i].announce();
	}
	delete [] zHorde;
	return 0; 
}