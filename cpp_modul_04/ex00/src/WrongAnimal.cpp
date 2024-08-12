# include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("no type set")
{
    std::cout << "Call " << MAGENTA << "Class WrongAnimal: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    this->_type = copy._type;
    std::cout << "Call " << MAGENTA << "Class WrongAnimal: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
    std::cout << "Call " << MAGENTA << "Class WrongAnimal: "  << this->_type << RESET <<  BACKGROUND_YELLOW << " Parmeter Constructor !" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "Use Operator (=) Overload " << MAGENTA << "from Class WrongAnimal: "  << src._type << " to Class WrongAnimal: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Call " << MAGENTA << "WrongAnimal" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string WrongAnimal::getType(void)const
{
    return this->_type; 
}

void WrongAnimal::setType(const std::string type)
{
    this->_type = type;
}

std::string WrongAnimal::setSpecialWrongAnimalSound()const
{
    return "Some generic WrongAnimal Sound"; 
}

void WrongAnimal::makeSound() const
{
    std::cout   << BRIGHT_CYAN << "WrongAnimal: " << getType() 
                << " --> Make Sound: \"" << setSpecialWrongAnimalSound() << "\""
                << RESET << std::endl;
}
