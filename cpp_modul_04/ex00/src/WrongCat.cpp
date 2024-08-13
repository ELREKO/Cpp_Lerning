# include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    setType("WrongCat");
    std::cout   << "Call " << FontColorTerminal::GREEN << "Class WrongCat: " << this->_type 
                << FontColorTerminal::RESET << FontColorTerminal::BACKGROUND_GREEN 
                << " Default Constructor !" << FontColorTerminal::RESET 
                << std::endl;
}


WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    this->_type = copy._type;
    std::cout   << "Call " << FontColorTerminal::GREEN << "Class WrongCat: " << this->_type 
                << FontColorTerminal::RESET <<  FontColorTerminal::BACKGROUND_BLUE << " Copy Constructor !" 
                << FontColorTerminal::RESET 
                << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
    std::cout   << "Use Operator (=) Overload " << FontColorTerminal::GREEN << "from Class WrongCat: "  
                << src._type << " to Class WrongCat: " << this->_type << FontColorTerminal::RESET 
                <<   " "   
                << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout   << "Call " << FontColorTerminal::GREEN << "WrongCat" 
                << FontColorTerminal::RESET << FontColorTerminal::BACKGROUND_RED 
                << " Deconstrucktor !" << FontColorTerminal::RESET 
                <<  std::endl;
}

void WrongCat::makeSound() const
{
    std::cout   << FontColorTerminal::BRIGHT_CYAN << "WrongAnimal: " << getType() 
                << " --> Make Sound: \"" << "Mieou" << "\""
                << FontColorTerminal::RESET << std::endl;
}

