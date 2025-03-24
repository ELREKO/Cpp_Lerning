# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "../../lib/console_setting/includes/FontColorTerminal.hpp"


class Bureaucrat
{
	private:
		const std::string _name;
    int _grade;
    
    void tryToSetGrade(int grade);

    void msg_const_destruc(const std::string msg) const;

  public:
    // Constructor 
    Bureaucrat();
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat(const std::string name);
    Bureaucrat(const int grade);
    Bureaucrat(const std::string name, int _grade);

    // Operater Overload
    Bureaucrat &operator=(const Bureaucrat &src);

    // Deconstructor 
    virtual ~Bureaucrat();

    // Member
    void incrementGrade();
    void decrementGrade();


    const std::string getName() const;
    int getGrade() const;   

    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

#endif