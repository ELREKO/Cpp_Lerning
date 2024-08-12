#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "../include/Unnecessary_ext_funkt.hpp"

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string weapon);
		~Weapon();
		const std::string getType(void);
		void setType(std::string);
};

#endif