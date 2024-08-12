#include "../includes/Character.hpp"


Character::Character(void): _name("default"), _inventory()
{
	std::cout << "Character created with default constructor" << std::endl;
}

Character::Character(std::string const &name): _name(name), _inventory()
{
	std::cout << "Character created "  << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character destroyed " <<  std::endl;
}

Character::Character(Character const &copy): ICharacter(copy), _inventory()
{
	this->_name = copy._name;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i];
	}
	std::cout << "Character copied" << std::endl;
}

Character const	&Character::operator=(const Character &copy)
{
	this->_name = copy._name;
	return (*this);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (m && this->_inventory[i] == NULL)
		{
			if (this->inInventory(m))
				this->_inventory[i] = m->clone();
			else
				this->_inventory[i] = m;
			std::cout << "Materia " << this->_inventory[i]->getType() << " equipped to " << this->_name << "'s inventory at index " << i << std::endl;
			return ;
		}
	}
	if (m)
		std::cout << RED << "Cannot equip materia, " <<  this->_name << "'s inventory is full!" << RESET <<std::endl;
	else
		std::cout << RED <<  "Cannot equip invalid materia" << RESET << std::endl;
	if (!this->inInventory(m))
		delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_ITEMS && this->_inventory[idx])
	{
		std::cout << "Unequipped " << this->_inventory[idx]->getType() << " from " << this->_name << "'s inventory at index " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
	else if (idx < 0 || idx >= MAX_ITEMS)
		std::cout << RED << "Cannot unequip materia, invalid index " << idx <<  RESET <<std::endl;
	else
		std::cout << RED <<  "Cannot unequip materia, index " << idx << " is empty!" <<  RESET <<std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < MAX_ITEMS && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else if (idx < 0 || idx >= MAX_ITEMS)
		std::cout << RED << "Cannot use materia, invalid index " << idx <<  RESET << std::endl;
	else
		std::cout << RED <<"Cannot use materia, index " << idx << " is empty!" << RESET << std::endl;
}

int Character::inInventory(AMateria *m)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (this->_inventory[i] == m)
			return (1);
	}
	return (0);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::setName(std::string const &name)
{
	this->_name = name;
}
