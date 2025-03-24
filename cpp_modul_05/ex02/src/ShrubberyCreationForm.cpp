# include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :\
		AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{
	std::cout 	<< FontColorTerminal::BLUE 
				<< "Shrubbery Creation Form Default Constructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :\
		AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout 	<< FontColorTerminal::BLUE 
				<< "Shrubbery Creation Form Default Constructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :\
		AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
		std::cout 	<< FontColorTerminal::BLUE 
					<< "Shrubbery Creation Form Copy Constructor Called! "
					<< FontColorTerminal::RESET << std::endl; 
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
	// Noting to set all Form main Attributes Privat or const; 
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout 	<< FontColorTerminal::BLUE 
				<< "Shrubbery Form Destructor! "
				<< FontColorTerminal::RESET << std::endl; 
}

// -------------------------------- Getter --------------------
std::string ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}


// -------------------------- Members ------------------
void ShrubberyCreationForm::excute(Bureaucrat const &executor) const
{
	try
	{
		if (this->checkExcecutePossible(executor, this->_target))
		{
			std::ofstream file((this->_target + "_shrubbery").c_str());

			// Überprüfe, ob die Datei erfolgreich geöffnet wurde
			if (!file.is_open()) {
				throw std::runtime_error("Failed to open file: " + this->_target + "_shrubbery");
			}

			// ASCII-Baum schreiben
			file << "   *\n";
			file << "  ***\n";
			file << " *****\n";
			file << "   |\n";
			file << "   |\n";

			// Datei schließen
			file.close();
			
			executor.executeForm(*this);
		}
	} 
	catch (const std::runtime_error& e) 
	{
    	std::cerr << "Error during execution: " << e.what() << std::endl;
	}
	executor.executeForm(*this);
}

