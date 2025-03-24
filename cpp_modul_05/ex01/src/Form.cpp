# include "../includes/Form.hpp"

// Constructo and Deconstructor 
Form::Form() : _name("no Form name"), _isSigned(false), _gradeSigned(150), _gradeExecute(150)
{
	msg_const_destruc("Default Constructor");
}
Form::Form(const std::string name) : _name(name), _isSigned(false), _gradeSigned(150), _gradeExecute(150)
{
	msg_const_destruc("Constructor");
}

Form::Form(const  int grSigned, const  int grExcecute) :\
			_name("no Form name"), _gradeSigned(tryToSetGrade(grSigned)), _gradeExecute(tryToSetGrade(grExcecute))
{
	msg_const_destruc("Constructor");
}

Form::Form(const std::string name, const  int grSigned, const  int grExcecute) :\
 			_name(name), _isSigned(false), _gradeSigned(tryToSetGrade(grSigned)), _gradeExecute(tryToSetGrade(grExcecute))
 {
	msg_const_destruc("Constructor");
 }

Form::Form(const Form &copy) : \
			_name(copy._name + "_copy"), _isSigned(copy._isSigned), \
			_gradeSigned(copy._gradeSigned), _gradeExecute(copy._gradeExecute)
{
	msg_const_destruc("Copy Constructor");
}
		
Form::~Form()
{
	msg_const_destruc("Destructor");
}

// Assignment operator
Form &Form::operator=(const Form &src)
{
	msg_const_destruc("Assignment Operator");
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return *this;
}


// -------------Getter----------------------

std::string Form::getAllFormInformation() const
{
	std::stringstream retString;
	retString	<< std::endl << "Formular Information:" << std::endl
				<< "Form Name	: " << this->_name << std::endl
				<< "Signded		: " << getIsSigndedString() << std::endl
				<< "Grade to Sig	: " << this->_gradeSigned << std::endl
				<< "Grade to Exe	: " << this->_gradeExecute;
	return retString.str(); 
}

std::string Form::getName() const
{
	return (this->_name);
}

std::string Form::getIsSigndedString() const
{
	if (this->_isSigned)
		return ("yes");
	return ("no");
}

bool Form::getIsSignded() const
{
	return (this->_isSigned);
}
 
int Form::getGradeSigned() const
{
	return (this->_gradeSigned);
}


int Form::getGradeExecute() const
{
	return (this->_gradeExecute);
}

// -------------------Setter--------------------- 
void Form::setIsSignded(const bool isSignded)
{
	this->_isSigned = isSignded;
}


// ------------- Member -------------------------
void Form::beSigned(const Bureaucrat &person)
{
	try
	{
		std::cout << FontColorTerminal::YELLOW  
		<< "Burocrat: " << person.getName() 
		<< ", is trying to Signed the Contract: " << this->getName()  
		<< std::endl;

		if (person.getGrade() > this->_gradeSigned)
		{
			throw Form::GradeTooLowException();
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
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << " for sign the Conract" << std::endl;
	}
	person.signForm(*this);
	std::cout << FontColorTerminal::RESET << std::endl;
}

// -------------privat members ------------------

void Form::msg_const_destruc(const std::string msg) const
{
std::cout 	<< FontColorTerminal::GREEN << msg << " called for Form: " 
			<< getAllFormInformation() << FontColorTerminal::RESET 
			<< std::endl << std::endl;
}

int Form::tryToSetGrade(const int grade) const
{
	try
	{
		if (grade > Grade_Min)
			throw Form::GradeTooLowException();
		else if (grade < Grade_Max)
			throw Form::GradeTooHighException();
	}
	catch(Form::GradeTooHighException &e)
	{ 
		std::cerr << e.what() << "set to the highest Grade!" << std::endl;
		return Grade_Max;
	}
	catch(Form::GradeTooLowException &e)
	{ 	
		std::cerr << e.what() << "set to the lowest Grade!" << std::endl;
		return Grade_Min;
	}
	return grade;
}


// ------ > Exception 
const char *Form::GradeTooHighException::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Grade too High!\n" + FontColorTerminal::RESET ;
    return errorMsg.c_str(); //convert to char 
}

const char *Form::GradeTooLowException::what() const throw()
{
    static std::string errorMsg;
    errorMsg = FontColorTerminal::RED + "ERR: Grade too Low!\n" + FontColorTerminal::RESET ;
    return errorMsg.c_str(); //convert to char 
}

// Assignent Operator for << 
std::ostream &operator<<(std::ostream& os, const Form &form)
{
	os	<< FontColorTerminal::BACKGROUND_GREEN 
		<< form.getAllFormInformation() << FontColorTerminal::RESET 
		<< FontColorTerminal::RESET
		<< std::endl << std::endl;
	return (os);
}


