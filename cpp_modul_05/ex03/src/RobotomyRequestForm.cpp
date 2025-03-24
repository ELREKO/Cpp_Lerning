# include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :\
		AForm("RobotomyRequestForm", 72, 45), _target("default_target")
{
	std::cout 	<< FontColorTerminal::GREEN 
				<< "RobotomyRequestForm Call Default Constructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :\
		AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout 	<< FontColorTerminal::GREEN 
				<< "RobotomyRequestForm Call Constructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :\
		AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
		std::cout 	<< FontColorTerminal::GREEN 
					<< "RobotomyRequestForm Call Copy Constructor"
					<< FontColorTerminal::RESET << std::endl; 
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
	// Noting to set all Form main Attributes Privat or const; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout 	<< FontColorTerminal::GREEN 
				<< "RobotomyRequestForm Form Destructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

// -------------------------------- Getter --------------------
std::string RobotomyRequestForm::getTarget()
{
	return (this->_target);
}


// -------------------------- Members ------------------
static unsigned int randomNbr = 0;

void RobotomyRequestForm::excute(Bureaucrat const &executor) const
{

	if (this->checkExcecutePossible(executor, this->_target))
	{
		std::cout << FontColorTerminal::BRIGHT_YELLOW << "brrrrrrr ...... brrrrrrr";
		//if (std::rand() % 2 == 0) //randomNbr Generate 
		if (randomNbr++ % 2 == 0)
		{
			std::cout 	<< ".......brrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl
						<< "Hy, " << this->_target << " Bureaucrat: " << executor.getGrade() << " has robtomized successfully";
		}
		else 
		{
			std::cout << std::endl << "Hy, " << this->_target << " sorry, Bureaucrat: " << executor.getGrade() << ", the robotomized faild";
		}
		std::cout << FontColorTerminal::RESET << std::endl;
	}
	
	executor.executeForm(*this);
}

