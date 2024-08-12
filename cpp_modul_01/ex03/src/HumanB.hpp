#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "../include/Unnecessary_ext_funkt.hpp"
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_Wepoan;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &Weapon);
};

#endif