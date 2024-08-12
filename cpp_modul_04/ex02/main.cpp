# include "includes/AAnimal.hpp"
# include "includes/Cat.hpp"
# include "includes/Dog.hpp"

#define MAX_ANIMALS 10

int main()
{
	AAnimal *animal = new Dog();
	animal->makeSound();
	delete animal;
	
}