# include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
    setType("Dog");
    std::cout << "Call " << YELLOW << "Class Dog: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}


Dog::Dog(const Dog& copy) : Animal(copy)
{
    this->_type = copy._type;
    std::cout << "Call " << YELLOW << "Class Dog: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
    std::cout << "Use Operator (=) Overload " << YELLOW << "from Class Dog: "  << src._type << " to Class Dog: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Call " << YELLOW << "Dog" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string Dog::setSpecialAnimalSound()const
{
    return "Woof"; 
}

