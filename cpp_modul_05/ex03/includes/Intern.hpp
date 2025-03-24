#ifndef INTERN_HPP
# define INTERN_HPP

# include "Header_Generally.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


# define MAX_FORMS 3

class Intern
{
private:
	AForm* (*make_Form[MAX_FORMS])(const std::string target);
	std::string formName[MAX_FORMS];
	void ArraySetting();

public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &src);

	~Intern();

	// Members
	AForm* makeForm(const std::string formName, const std::string targetName);

	class NoFormsException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};





# endif