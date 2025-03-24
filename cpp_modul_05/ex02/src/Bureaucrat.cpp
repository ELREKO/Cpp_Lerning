#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

// Constructor and Destructor
Bureaucrat::Bureaucrat() : _name("default_name"), _grade(150)
{
	msg_const_destruc("Default Constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name + "_copy"), _grade(copy._grade)
{	
	msg_const_destruc("Copy Constructor");
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	msg_const_destruc("Constructor");
}

Bureaucrat::Bureaucrat(const  int grade) : _name("default_name")
{
	msg_const_destruc("Constructor");
	tryToSetGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, const  int grade) : _name(name)
{
	msg_const_destruc("Constructor");
	tryToSetGrade(grade);

}

void Bureaucrat::tryToSetGrade( int grade)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = grade;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << " Grade set to the Highest 1" << std::endl;
		this->_grade = 1;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << " Grade set to the lowest 150" << std::endl;
		this->_grade = 150;
	}
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	msg_const_destruc("Destructor");
}

// Assignment operator
 Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
 {
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	msg_const_destruc("Assignment operator");
	return (*this);
 }

// ---------- getter ----------------

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}
int Bureaucrat::getGrade() const
{
	return (this->_grade);
} 

// ----------other Member -----------
void Bureaucrat::incrementGrade()
{
	std::cout << "Traying to increment Garde!" << std::endl;
	tryToSetGrade(this->_grade - 1);
	std::cout << "Bureaucrat: " << getName() << " have now the grade " << getGrade() << std::endl; 
}
void Bureaucrat::decrementGrade()
{
	std::cout << "Traying to decrement Garde!" << std::endl;
	tryToSetGrade(this->_grade + 1);
	std::cout << "Bureaucrat: " << getName() << " have now the grade " << getGrade() << std::endl; 
}


void Bureaucrat::signForm(AForm &formular) const
{
	std::cout << std::endl << FontColorTerminal::YELLOW;
	if (formular.getGradeSigned() >= this->getGrade())
	{
		if (!formular.getIsSignded())
		{
			std::cout 	<< this->_name << " signed  " 
						<< formular.getName();
			formular.setIsSignded(true);
		}
		else
		{
			std::cout 	<< this->_name << " couldn't sigend " 
						<< formular.getName()  
						<< ", because the form isSigned!";
		}
	}
	else 
		std::cout 	<< this->_name << " couldn’t sign  " 
					<< formular.getName()  
					<< ", because a wrong grad of the bureaucrat ";	
	std::cout << FontColorTerminal::RESET << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	std::cout << FontColorTerminal::MAGENTA <<std::endl;
	if (form.getGradeExecute() >= this->getGrade())
	{
		std::cout 	<< this->_name << " executed " 
					<< form.getName()  << std::endl;
		std::cout 	<< FontColorTerminal::BACKGROUND_RED 
					<< "Excecute" << FontColorTerminal::RESET 
					<< std::endl;
	}
	else 
		std::cout 	<< this->_name << " couldn’t execute " 
					<< form.getName()  
					<< " because a wrong grad of the bureaucrat ";	
	std::cout << FontColorTerminal::RESET << std::endl;
}

// -------------privat members ------------------

void Bureaucrat::msg_const_destruc(const std::string msg) const
{
std::cout 	<< FontColorTerminal::BLUE << msg << " called for Bureaucrat: " << getName() 
			<< FontColorTerminal::RESET << std::endl; 	
}

// ----------------nested class --------------

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Grade too high!\n" + FontColorTerminal::RESET;
    return errorMsg.c_str(); //convert to char 
}
  

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Grade too Low!\n" + FontColorTerminal::RESET ;
    return errorMsg.c_str(); //convert to char 
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os 	<< bureaucrat.getName() 
		<< ", bureaucrat grade " 
		<< bureaucrat.getGrade() << "." 
		<< std::endl;
	return (os);
}