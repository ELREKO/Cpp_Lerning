# include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    setType("WrongCat");
    std::cout << "Call " << GREEN << "Class WrongCat: " << this->_type << RESET << BACKGROUND_GREEN << " Default Constructor !" << RESET << std::endl;
}


WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    this->_type = copy._type;
    std::cout << "Call " << GREEN << "Class WrongCat: " << this->_type << RESET <<  BACKGROUND_BLUE << " Copy Constructor !" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
    std::cout << "Use Operator (=) Overload " << GREEN << "from Class WrongCat: "  << src._type << " to Class WrongCat: " << this->_type << RESET <<   " "   << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Call " << GREEN << "WrongCat" << RESET << BACKGROUND_RED << " Deconstrucktor !" << RESET <<  std::endl;
}

std::string WrongCat::setSpecialAnimalSound()const
{
    return "Wrong_Miau"; 
}

