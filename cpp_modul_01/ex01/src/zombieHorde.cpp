#include "../includes/Zombie_main.hpp"

static std::string int_to_string(int nbr);

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].setZombieName(name  + "_" + int_to_string(i));
	}
	return (zombie_horde);
}

static std::string int_to_string(int nbr)
{
    std::stringstream ss;
    ss << nbr;
    return(ss.str()); 
}

