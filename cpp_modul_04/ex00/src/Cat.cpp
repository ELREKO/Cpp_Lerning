# include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "cat";
    std::cout   << "Call " << FontColorTerminal::GREEN << "Class Cat: " << this->_type 
                << FontColorTerminal::RESET << FontColorTerminal::BACKGROUND_GREEN 
                << " Default Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}


Cat::Cat(const Cat& copy) : Animal(copy)
{
    this->_type = copy._type;
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
    }
    return *this;
}

Cat::~Cat()
{
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

