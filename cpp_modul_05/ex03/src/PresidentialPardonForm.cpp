# include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :\
		AForm("PresidentialPardonForm", 25, 5), _target("default_target")
{
	std::cout 	<< FontColorTerminal::UNDERLINE 
				<< "PresidentialPardonForm Call Default Constructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :\
		AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout 	<< FontColorTerminal::UNDERLINE 
				<< "PresidentialPardonForm Call Constructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :\
		AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
		std::cout 	<< FontColorTerminal::UNDERLINE 
					<< "PresidentialPardonForm Call Copy Constructor"
					<< FontColorTerminal::RESET << std::endl; 
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
	// Noting to set all Form main Attributes Privat or const; 
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout 	<< FontColorTerminal::UNDERLINE 
				<< "PresidentialPardonForm Form Destructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

// -------------------------------- Getter --------------------
std::string PresidentialPardonForm::getTarget()
{
	return (this->_target);
}


// -------------------------- Members -----------------
void PresidentialPardonForm::excute(Bureaucrat const &executor) const
{

	if (this->checkExcecutePossible(executor, this->_target))
	{
		std::cout 	<< FontColorTerminal::BRIGHT_YELLOW 
					<< this->_target << " has been pardoned by Zaphod Beeblebrox"
					<< FontColorTerminal::RESET << std::endl;
	}
	
	executor.executeForm(*this);
}

