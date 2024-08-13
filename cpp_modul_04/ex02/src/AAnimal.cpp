# include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("no type set")
{
    
    std::cout   << "Call " << FontColorTerminal::RED 
                << "Class AAnimal: " << this->_type << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_GREEN << " Default Constructor !" 
                << FontColorTerminal::RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
    this->_type = copy._type;
    std::cout   << "Call " << FontColorTerminal::RED 
                << "Class AAnimal: " << this->_type << FontColorTerminal::RESET 
                <<  FontColorTerminal::BACKGROUND_BLUE << " Copy Constructor !" 
                << FontColorTerminal::RESET << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type)
{
    std::cout   << "Call " << FontColorTerminal::RED
                << "Class AAnimal: "  << this->_type << FontColorTerminal::RESET 
                <<  FontColorTerminal::BACKGROUND_YELLOW << " Parmeter Constructor !" 
                << FontColorTerminal::RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
    std::cout   << "Use Operator (=) Overload " 
                << FontColorTerminal::RED << "from Class AAnimal: "  
                << src._type << " to Class AAnimal: " << this->_type << FontColorTerminal::RESET 
                <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout   << "Call " << FontColorTerminal::RED << "AAnimal" << FontColorTerminal::RESET 
                << FontColorTerminal::BACKGROUND_RED << " Deconstrucktor !"
                << FontColorTerminal::RESET <<  std::endl;
}

std::string AAnimal::getType(void)const
{
    return this->_type; 
}

void AAnimal::setType(const std::string type)
{
    this->_type = type;
}

// //  Is a pure Virtual Class 
// // ----------------
// void AAnimal::makeSound() const
// {
//     std::cout   << FontColorTerminal::BRIGHT_CYAN << "AAnimal: " << getType() 
//                 << " --> Make Sound: \"" << "Some AAnimal make some special Sound" << "\""
//                 << FontColorTerminal::RESET << std::endl;
// }
