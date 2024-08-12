# include "../includes/Animal.hpp"

Animal::Animal() : _type("no type set")
{
    std::cout << "Call " << RED << "Class Animal: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}

Animal::Animal(const Animal& copy)
{
    this->_type = copy._type;
    std::cout << "Call " << RED << "Class Animal: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
    std::cout << "Call " << RED << "Class Animal: "  << this->_type << RESET <<  BACKGROUND_YELLOW << " Parmeter Constructor !" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal &src)
{
    std::cout << "Use Operator (=) Overload " << RED << "from Class Animal: "  << src._type << " to Class Animal: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Call " << RED << "Animal" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string Animal::getType(void)const
{
    return this->_type; 
}

void Animal::setType(const std::string type)
{
    this->_type = type;
}

std::string Animal::setSpecialAnimalSound()const
{
    return "Some generic Animal Sound"; 
}

void Animal::makeSound() const
{
    std::cout   << BRIGHT_CYAN << "Animal: " << getType() 
                << " --> Make Sound: \"" << setSpecialAnimalSound() << "\""
                << RESET << std::endl;
}
