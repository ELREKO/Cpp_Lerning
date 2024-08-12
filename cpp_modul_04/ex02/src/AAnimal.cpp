# include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("no type set")
{
    std::cout << "Call " << RED << "Class AAnimal: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
    this->_type = copy._type;
    std::cout << "Call " << RED << "Class AAnimal: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type)
{
    std::cout << "Call " << RED << "Class AAnimal: "  << this->_type << RESET <<  BACKGROUND_YELLOW << " Parmeter Constructor !" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
    std::cout << "Use Operator (=) Overload " << RED << "from Class AAnimal: "  << src._type << " to Class AAnimal: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Call " << RED << "AAnimal" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string AAnimal::getType(void)const
{
    return this->_type; 
}

void AAnimal::setType(const std::string type)
{
    this->_type = type;
}

void AAnimal::makeSound() const
{
    std::cout   << BRIGHT_CYAN << "Animal: " << getType() 
                << " --> Make Sound: \"" << setSpecialAnimalSound() << "\""
                << RESET << std::endl;
}
