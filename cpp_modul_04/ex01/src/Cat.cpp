# include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "cat";
    this->_brain = new Brain;
    std::cout   << "Call " << FontColorTerminal::GREEN << "Class Cat: " << this->_type 
                << FontColorTerminal::RESET << FontColorTerminal::BACKGROUND_GREEN 
                << " Default Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}


Cat::Cat(const Cat& copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain (*copy._brain);
    std::cout   << "Call " << FontColorTerminal::GREEN << "Class Cat: " 
                << this->_type << FontColorTerminal::RESET <<  FontColorTerminal::BACKGROUND_BLUE 
                << " Copy Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
    std::cout   << "Use Operator (=) Overload " << FontColorTerminal::GREEN 
                << "from Class Cat: "  << src._type << " to Class Cat: " << this->_type 
                << FontColorTerminal::RESET <<   " " 
                << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout   << "Call " << FontColorTerminal::GREEN << "Cat" << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_RED << " Deconstrucktor !" 
                << FontColorTerminal::RESET <<  std::endl;
}

void Cat::makeSound() const
{
    std::cout   << FontColorTerminal::BRIGHT_CYAN << "Animal: " << getType() 
                << " --> Make Sound: \"" << "Miou" << "\""
                << FontColorTerminal::RESET << std::endl;
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