# include "../includes/AForm.hpp"

// Constructo and Deconstructor 
AForm::AForm() : _name("no AForm name"), _isSigned(false), _gradeSigned(150), _gradeExecute(150)
{
	msg_const_destruc("Default Constructor");
}
AForm::AForm(const std::string name) : _name(name), _isSigned(false), _gradeSigned(150), _gradeExecute(150)
{
	msg_const_destruc("Constructor");
}

AForm::AForm(const  int grSigned, const  int grExcecute) :\
			_name("no AForm name"), _gradeSigned(tryToSetGrade(grSigned)), _gradeExecute(tryToSetGrade(grExcecute))
{
	msg_const_destruc("Constructor");
}

AForm::AForm(const std::string name, const  int grSigned, const  int grExcecute) :\
 			_name(name), _isSigned(false), _gradeSigned(tryToSetGrade(grSigned)), _gradeExecute(tryToSetGrade(grExcecute))
 {
	msg_const_destruc("Constructor");
 }

AForm::AForm(const AForm &copy) : \
			_name(copy._name + "_copy"), _isSigned(copy._isSigned), \
			_gradeSigned(copy._gradeSigned), _gradeExecute(copy._gradeExecute)
{
	msg_const_destruc("Copy Constructor");
}
		
AForm::~AForm()
{
	//msg_const_destruc("Destructor");
}

// Assignment operator
AForm &AForm::operator=(const AForm &src)
{
	msg_const_destruc("Assignment Operator");
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return *this;
}


// -------------Getter----------------------

std::string AForm::getAllAFormInformation() const
{
	std::stringstream retString;
	retString	<< std::endl << "Formular Information:" << std::endl
				<< "AForm Name	: " << this->_name << std::endl
				<< "Signded		: " << getIsSigndedString() << std::endl
				<< "Grade to Sig	: " << this->_gradeSigned << std::endl
				<< "Grade to Exe	: " << this->_gradeExecute;
	return retString.str(); 
}

std::string AForm::getName() const
{
	return (this->_name);
}


std::string AForm::getIsSigndedString() const
{
	if (this->_isSigned)
		return ("yes");
	return ("no");
}

bool AForm::getIsSignded() const
{
	return (this->_isSigned);
}

int AForm::getGradeSigned() const
{
	return (this->_gradeSigned);
}


int AForm::getGradeExecute() const
{
	return (this->_gradeExecute);
}


// -------------------Setter--------------------- 
void AForm::setIsSignded(const bool isSignded)
{
	this->_isSigned = isSignded;
}


// ------------- Member -------------------------
void AForm::beSigned(const Bureaucrat &person)
{
	try
	{
		std::cout << FontColorTerminal::YELLOW  
		<< "Burocrat: " << person.getName() 
		<< ", is trying to Signed the Contract: " << this->getName()
		<< std::endl;

		if (person.getGrade() > this->_gradeSigned)
		{
			throw AForm::GradeTooLowException();
		}
		else if (person.getGrade() <= this->_gradeSigned)
		{
			if (!this->_isSigned)
			{
				std::cout 	<< "Form \"" << this->getName() 
							<< "\"" << "is Signed by \"" << person.getName();			
			}
			else
			{
				std::cout << "The form is already signed!" << std::endl;
			}
		}
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << " for sign the Conract" << std::endl;
	}
	person.signForm(*this);
	std::cout << FontColorTerminal::RESET << std::endl;
}


bool AForm::checkExcecutePossible(Bureaucrat const &executor, const std::string target) const
{
	std::cout 	<< FontColorTerminal::MAGENTA  
				<< "Bureaucrat: " << executor.getName() 
				<<", try to Execute the Form: " << this->getName() << ", with target: " << target
				<< FontColorTerminal::RESET <<  std::endl << std::endl;
	try
	{

		if (!this->getIsSignded())
			throw AForm::FormNotSigned();
		else if (executor.getGrade() > this->getGradeExecute())
			throw AForm::GradeTooLowException();
		else
			return true;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << "to Execute the Form" << std::endl;
		return false;
	}
	catch(AForm::FormNotSigned &e)
	{
		std::cerr << e.what();
		return false;
	}
}

// -------------privat members ------------------

void AForm::msg_const_destruc(const std::string msg) const
{
std::cout 	<< FontColorTerminal::GREEN << msg << " called for AForm: " 
			<< getAllAFormInformation() << FontColorTerminal::RESET 
			<< std::endl << std::endl;
}

int AForm::tryToSetGrade(const int grade) const
{
	try
	{
		if (grade > Grade_Min)
			throw AForm::GradeTooLowException();
		else if (grade < Grade_Max)
			throw AForm::GradeTooHighException();
	}
	catch(AForm::GradeTooHighException &e)
	{ 
		std::cerr << e.what() << "set to the highest Grade!" << std::endl;
		return Grade_Max;
	}
	catch(AForm::GradeTooLowException &e)
	{ 	
		std::cerr << e.what() << "set to the lowest Grade!" << std::endl;
		return Grade_Min;
	}
	return grade;
}


// ------ > Exception 
const char *AForm::GradeTooHighException::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Grade too High!\n" + FontColorTerminal::RESET ;
    return errorMsg.c_str(); //convert to char 
}

const char *AForm::GradeTooLowException::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Grade too Low!\n" + FontColorTerminal::RESET ;
    return errorMsg.c_str(); //convert to char 
}

const char *AForm::FormNotSigned::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Form Is Not Signed!\n" + FontColorTerminal::RESET ;
    return errorMsg.c_str(); //convert to char 
}

// Assignent Operator for << 
std::ostream &operator<<(std::ostream& os, const AForm &form)
{
	os	<< FontColorTerminal::BACKGROUND_GREEN 
		<< form.getAllAFormInformation() << FontColorTerminal::RESET 
		<< FontColorTerminal::RESET
		<< std::endl << std::endl;
	return (os);
}


