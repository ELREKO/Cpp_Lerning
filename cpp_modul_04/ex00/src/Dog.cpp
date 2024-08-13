# include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    std::cout   << "Call " << FontColorTerminal::YELLOW 
                << "Class Dog: " << this->_type << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_GREEN 
                << " Default Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}


Dog::Dog(const Dog& copy) : Animal(copy)
{
    this->_type = copy._type;
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
    }
    return *this;
}

Dog::~Dog()
{
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

