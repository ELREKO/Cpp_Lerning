#include "../includes/Intern.hpp"

Intern::Intern()
{
	this->ArraySetting();
	std::cout << "Intern Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	for (int i = 0; i < MAX_FORMS; i++)
	{
		this->make_Form[i] = copy.make_Form[i];
		this->formName[i] = copy.formName[i];
	}
	std::cout << "Intern Copy Constctor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	return *this;
}

AForm* makeFormShrubbery (const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* makeFormRobotomy (const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* makeFormPresidential (const std::string target)
{
	return (new PresidentialPardonForm(target));
}

// Members
AForm* Intern::makeForm(const std::string formName, const std::string targetName)
{
	AForm* form = NULL;
	try
	{
		std::cout << "Intern try to create Form: " << formName << std::endl;
		for(int i=0; i < MAX_FORMS; i++)
		{
			if (this->formName[i] == formName)
			{
				form = this->make_Form[i](targetName);
				std::cout << "Intern creates " << formName << std::endl;
			}
		}
		if (form == NULL)
			throw Intern::NoFormsException();
		
	}
	catch(Intern::NoFormsException &e)
	{
		std::cerr << std::endl
			<< "Intern couldn't create From: " <<  formName 
			<< " " << e.what() << std::endl;
	}
	return form;
}

// Exception Class 
const char* Intern::NoFormsException::what() const throw()
{
	static std::string errorMsg;
	errorMsg = FontColorTerminal::RED + "\n ERR: No Forms Found!" + FontColorTerminal::RESET + "\n";
    return errorMsg.c_str();
}

// privat Member 
void Intern::ArraySetting()
{
	this->make_Form[0] = &makeFormShrubbery;
	this->make_Form[1] = &makeFormRobotomy;
	this->make_Form[2] = &makeFormPresidential;

	this->formName[0] = "ShrubberyCreationForm";
	this->formName[1] = "RobotomyRequestForm";
	this->formName[2] = "PresidentialPardonForm";
}