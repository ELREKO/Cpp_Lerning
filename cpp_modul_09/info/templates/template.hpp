

#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>

class templates
{
private:
	std::string _name;
	int _hit_points;
	int _energy_points;
	int _attack_damage;

protected: 
	//Getter 
	std::string getName();
	unsigned int getHitPoints();
	unsigned int getEneryPoints();
	unsigned int getAttackDamage();

	//Setter
	void setName(std::string name);
	void setHitPoints(unsigned int hit_ponts);
	void setEnergyPoints(unsigned int energy_Points);
	void setAttackDamage(unsigned int attack_damage);

public:
	//Constucter
	templates();
	templates(const templates& copy);
	templates(std::string name);
	
	// Overloaded Operators
	templates& operator=(const templates& src);

	//Deconstructor
	~templates();

	//Move constructer and -overload operator 
	templates(templates&& other);
	templates& operator=(templates&& ohter);
};

#endif