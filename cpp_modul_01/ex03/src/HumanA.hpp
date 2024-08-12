#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "../include/Unnecessary_ext_funkt.hpp"
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon _Wepoan;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
		void setWeapon(Weapon &Weapon);
};

#endif