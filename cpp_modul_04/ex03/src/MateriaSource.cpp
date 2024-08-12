#include "../includes/MateriaSource.hpp"


MateriaSource::MateriaSource(void): _learnInventory()
{
	std::cout << "MateriaSource created with default constructor" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MAX_LEARN_INVENRORY; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy): IMateriaSource(copy), _learnInventory()
{
	for (int i = 0; i < MAX_LEARN_INVENRORY; i++)
	{
		if (copy._learnInventory[i])
			this->_learnInventory[i] = copy._learnInventory[i];
	}
	std::cout << "MateriaSource copied" << std::endl;
}

MateriaSource const	&MateriaSource::operator=(const MateriaSource &copy)
{
	(void)copy;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MAX_LEARN_INVENRORY; i++)
	{
		if (materia && this->_learnInventory[i] == NULL)
		{
			if (this->inLearnInventory(materia))
				this->_learnInventory[i] = materia;
			else
				this->_learnInventory[i] = materia;
			std::cout << "Materia " << this->_learnInventory[i]->getType() << " learned at index " << i << std::endl;
			return ;
		}
	}
	if (materia)
		std::cout << YELLOW  <<"Cannot learn materia, inventory for MateriaSource is full!" << RESET << std::endl;
	else
		std::cout << YELLOW  <<"Cannot learn invalid materia" << RESET << std::endl;
	if (!this->inLearnInventory(materia))
		delete materia;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < MAX_LEARN_INVENRORY; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (this->_learnInventory[i]->clone());
	}
	std::cout << YELLOW  << "Cannot create materia, " << type << " is invalid!" << RESET << std::endl;
	return (0);
}

int MateriaSource::inLearnInventory(AMateria *materia)
{
	for (int i = 0; i < MAX_LEARN_INVENRORY; i++)
	{
		if (this->_learnInventory[i] == materia)
			return (1);
	}
	return (0);
}
