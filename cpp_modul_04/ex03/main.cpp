

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() 
{
	{
		Ice 	iceWappen;
		Cure	cureSkill;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		src->learnMateria(iceWappen.clone());
		src->learnMateria(cureSkill.clone());
		src->learnMateria(cureSkill.clone());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("Arrow");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(-4, *bob);
		me->use(4, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}
}
