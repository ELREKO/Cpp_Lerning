#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "../includes/Zombie_ext_funk.hpp"

class Zombie 
{
	private:
		std::string _name;

	public:
		Zombie( std::string name);
		Zombie(void);
		~Zombie(void);
		void announce( void );
		void setZombieName (std::string name);
};


#endif