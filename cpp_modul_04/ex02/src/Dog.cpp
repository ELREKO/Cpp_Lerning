# include "../includes/Dog.hpp"
# include "../includes/Brain.hpp"

Dog::Dog() : AAnimal()
{
    setType("Dog");
    this->_brain = new Brain;
    checkBarinAllocation();
    std::cout << "Call " << YELLOW << "Class Dog: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}


Dog::Dog(const Dog& copy) : AAnimal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain (*copy._brain);
    checkBarinAllocation();
    std::cout << "Call " << YELLOW << "Class Dog: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
    std::cout << "Use Operator (=) Overload " << YELLOW << "from Class Dog: "  << src._type << " to Class Dog: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = src._brain;
        checkBarinAllocation();
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Call " << YELLOW << "Dog" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string Dog::setSpecialAnimalSound()const
{
    return "Woof"; 
}

void Dog::checkBarinAllocation()
{
    if (this->_brain == NULL)
    {   
		throw std::runtime_error("Error: Allocation Barin!");
    }
}

void Dog::setIdea(const unsigned nbr, const std::string idea)
{
    this->_brain->setIdea(nbr, idea);
}


void Dog::getAllIdeas()
{
    std::cout << "Animal: " << getType() << " have follow ideas: " << std::endl;  
    for (unsigned int i = 0; i < MAX_IDEAS; i++)
    {
        if (!getIdea(i).empty())
        {
            std::cout << "Idea nbr: " << i << " -- > \"" << getIdea(i) << "\"" << std::endl;
        }
    }
}

std::string Dog::getIdea(const unsigned int nbr)
{  
   return this->_brain->getIdea(nbr);
}
