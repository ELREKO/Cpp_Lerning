# include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
    setType("Cat");
    std::cout << "Call " << GREEN << "Class Cat: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}


Cat::Cat(const Cat& copy) : Animal(copy)
{
    this->_type = copy._type;
    std::cout << "Call " << GREEN << "Class Cat: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
    std::cout << "Use Operator (=) Overload " << GREEN << "from Class Cat: "  << src._type << " to Class Cat: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Call " << GREEN << "Cat" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string Cat::setSpecialAnimalSound()const
{
    return "Miau"; 
}

