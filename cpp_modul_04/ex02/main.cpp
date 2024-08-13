# include "includes/AAnimal.hpp"
# include "includes/Cat.hpp"
# include "includes/Dog.hpp"

#define MAX_ANIMALS 10

int main()
{	
	// Animal test;
	AAnimal *meta[100];
	// meta[0]->makeSound();

	for (unsigned int i = 0; i < MAX_ANIMALS; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
		}
		else
		{
			meta[i] = new Dog();
		}
	}

	for (unsigned int i = 0; i < MAX_ANIMALS; i++)
	{
		meta[i]->makeSound();
	}

	for (unsigned int i = 0; i < MAX_ANIMALS; i++)
	{
		delete meta[i];
	}

	std::cout << std::endl << std::endl;

	Dog* Bello_1 = new Dog;

	 
	Bello_1->setIdea(0, "bark!");
	Bello_1->setIdea(1, "sniffe");
	Bello_1->setIdea(101, "Could i so much think?");

	Dog* Bello_2 = new Dog(*Bello_1);

	Bello_2->setIdea(2, "Please take a walk");
	Bello_2->setIdea(3, "Have a nap");
	Bello_2->setIdea(4, "My master is the best");
	Bello_2->setIdea(5, "Look at him loving");
	Bello_2->setIdea(6, "Hunt the cat");

	Bello_2->getAllIdeas();
	Bello_1->getIdea(20);

	std::cout << std::endl << std::endl << "Test Deep Copy" << std::endl;
	{
		Dog basic(*Bello_2);
		basic.getAllIdeas();
	}

	Bello_2->getAllIdeas();
	//basic.getAllIdeas();

	delete Bello_1;
	delete Bello_2;

}