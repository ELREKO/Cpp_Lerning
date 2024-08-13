# include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("no type set")
{
    std::cout   << "Call " << FontColorTerminal::MAGENTA << "Class WrongAnimal: " 
                << this->_type << FontColorTerminal::RESET << FontColorTerminal::BACKGROUND_GREEN 
                << " Default Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    this->_type = copy._type;
    std::cout   << "Call " << FontColorTerminal::MAGENTA << "Class WrongAnimal: " 
                << this->_type << FontColorTerminal::RESET <<  FontColorTerminal::BACKGROUND_BLUE 
                << " Copy Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
    std::cout << "Call "    << FontColorTerminal::MAGENTA << "Class WrongAnimal: "  
                            << this->_type << FontColorTerminal::RESET <<  FontColorTerminal::BACKGROUND_YELLOW 
                            << " Parmeter Constructor !" << FontColorTerminal::RESET 
                            << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout   << "Use Operator (=) Overload " << FontColorTerminal::MAGENTA 
                << "from Class WrongAnimal: "  << src._type << " to Class WrongAnimal: " 
                << this->_type << FontColorTerminal::RESET   
                << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout   << "Call " << FontColorTerminal::MAGENTA << "WrongAnimal" << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_RED << " Deconstrucktor !" << FontColorTerminal::RESET 
                <<  std::endl;
}

std::string WrongAnimal::getType(void)const
{
    return this->_type; 
}

void WrongAnimal::setType(const std::string type)
{
    this->_type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout   << FontColorTerminal::BRIGHT_CYAN << "WrongAnimal: " << getType() 
                << " --> Make Sound: \"" << "Some Animal make some Sound" << "\""
                << FontColorTerminal::RESET << std::endl;
}
