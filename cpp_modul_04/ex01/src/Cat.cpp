# include "../includes/Cat.hpp"
# include "../includes/Brain.hpp"

Cat::Cat() : Animal()
{
    setType("Cat");
    this->_brain = new Brain;
    checkBarinAllocation();
    std::cout << "Call " << GREEN << "Class Cat: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}


Cat::Cat(const Cat& copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    checkBarinAllocation();
    std::cout << "Call " << GREEN << "Class Cat: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
    std::cout << "Use Operator (=) Overload " << GREEN << "from Class Cat: "  << src._type << " to Class Cat: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
        checkBarinAllocation();
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Call " << GREEN << "Cat" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string Cat::setSpecialAnimalSound()const
{
    return "Miau"; 
}

void Cat::checkBarinAllocation()
{
    if (this->_brain == NULL)
    {   
		throw std::runtime_error("Error: Allocation Barin!");
    }
}

void Cat::setIdea(const unsigned nbr, const std::string idea)
{
    this->_brain->setIdea(nbr, idea);
}


void Cat::getAllIdeas()
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

std::string Cat::getIdea(const unsigned int nbr)
{
   return this->_brain->getIdea(nbr) ;
}