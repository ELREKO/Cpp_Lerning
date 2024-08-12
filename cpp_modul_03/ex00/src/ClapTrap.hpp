
#include <string>
#include <iostream>
#include "../../lib/console_setting/color.h"

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

class ClapTrap
{

private:
	//Attributs 
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
	unsigned int _max_repair;

protected:

	//Getter 
	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEneryPoints() const;
	unsigned int getAttackDamage() const;
	unsigned int getMaxRepair() const;
	void getStatus(const std::string& prefix = "") const;

	//Setter
	void setName(const std::string name);
	void setHitPoints(const unsigned int hit_ponts);
	void setEnergyPoints(const unsigned int energy_Points);
	void setAttackDamage(const unsigned int attack_damage);
	void setMaxRepair(const unsigned int max_repair); 
	void setMainAttributs(const std::string name);
	void setAllMainAttributsCopy(const ClapTrap& copy);
	

public:
	//Constucter
	ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap(std::string name);
	
	// Overloaded Operators
	ClapTrap& operator=(const ClapTrap& src);

	//Deconstructor
	virtual ~ClapTrap();

	/* --> not allowed for the execice --> becouse cpp std=98
	//Move constructer and -overload operator 
	ClapTrap(ClapTrap&& other);
	ClapTrap& operator=(ClapTrap&& ohter);
	*/

	//Members 
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif