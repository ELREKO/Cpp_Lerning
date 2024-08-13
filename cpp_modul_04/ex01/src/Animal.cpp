# include "../includes/Animal.hpp"

Animal::Animal() : _type("no type set")
{
    
    std::cout   << "Call " << FontColorTerminal::RED 
                << "Class Animal: " << this->_type << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_GREEN << " Default Constructor !" 
                << FontColorTerminal::RESET << std::endl;
}

Animal::Animal(const Animal& copy)
{
    this->_type = copy._type;
    std::cout   << "Call " << FontColorTerminal::RED 
                << "Class Animal: " << this->_type << FontColorTerminal::RESET 
                <<  FontColorTerminal::BACKGROUND_BLUE << " Copy Constructor !" 
                << FontColorTerminal::RESET << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
    std::cout   << "Call " << FontColorTerminal::RED
                << "Class Animal: "  << this->_type << FontColorTerminal::RESET 
                <<  FontColorTerminal::BACKGROUND_YELLOW << " Parmeter Constructor !" 
                << FontColorTerminal::RESET << std::endl;
}

Animal& Animal::operator=(const Animal &src)
{
    std::cout   << "Use Operator (=) Overload " 
                << FontColorTerminal::RED << "from Class Animal: "  
                << src._type << " to Class Animal: " << this->_type << FontColorTerminal::RESET 
                <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout   << "Call " << FontColorTerminal::RED << "Animal" << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_RED << " Deconstrucktor !"
                << FontColorTerminal::RESET <<  std::endl;
}

std::string Animal::getType(void)const
{
    return this->_type; 
}

void Animal::setType(const std::string type)
{
    this->_type = type;
}


void Animal::makeSound() const
{
    std::cout   << FontColorTerminal::BRIGHT_CYAN << "Animal: " << getType() 
                << " --> Make Sound: \"" << "Some Animal make some special Sound" << "\""
                << FontColorTerminal::RESET << std::endl;
}
