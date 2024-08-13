# include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    this->_brain = new Brain;
    std::cout   << "Call " << FontColorTerminal::YELLOW 
                << "Class Dog: " << this->_type << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_GREEN 
                << " Default Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}


Dog::Dog(const Dog& copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain (*copy._brain);
    std::cout   << "Call " << FontColorTerminal::YELLOW << "Class Dog: " << this->_type 
                << FontColorTerminal::RESET <<  FontColorTerminal::BACKGROUND_BLUE 
                << " Copy Constructor !" << FontColorTerminal::RESET << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
    std::cout   << "Use Operator (=) Overload " << FontColorTerminal::YELLOW 
                << "from Class Dog: "  << src._type << " to Class Dog: " << this->_type 
                << FontColorTerminal::RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout   << "Call " << FontColorTerminal::YELLOW << "Dog" 
                << FontColorTerminal::RESET << FontColorTerminal::BACKGROUND_RED 
                << " Deconstrucktor !" << FontColorTerminal::RESET 
                <<  std::endl;
}

void Dog::makeSound() const
{
    std::cout   << FontColorTerminal::BRIGHT_CYAN << "Animal: " << getType() 
                << " --> Make Sound: \"" << "Woof" << "\""
                << FontColorTerminal::RESET << std::endl;
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
   return this->_brain->getIdea(nbr) ;
}