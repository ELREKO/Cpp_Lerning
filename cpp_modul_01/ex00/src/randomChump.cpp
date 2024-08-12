#include "../includes/Zombie_main.hpp"

void randomChump( std::string name )
{
	Zombie z = Zombie(name);
	z.announce();
	return ;
}