# include "includes/Animal.hpp"
# include "includes/Cat.hpp"
# include "includes/Dog.hpp"
# include "includes/WrongAnimal.hpp"
# include "includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout  << std::endl << std::endl;

	const WrongAnimal* WAnimal = new WrongAnimal();
	const WrongAnimal* WCat = new WrongCat();

	WAnimal->makeSound();
	WCat->makeSound();

	delete WAnimal;
	delete WCat;

	std::cout  << std::endl << std::endl;
	
	return 0;
}