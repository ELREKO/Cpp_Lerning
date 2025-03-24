

# ifndef FORM_HPP
# define FORM_HPP

# include "Header_Generally.hpp"
# include "Bureaucrat.hpp"


class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const  int _gradeSigned;
		const  int _gradeExecute;

		int tryToSetGrade(const  int grade) const;

		void msg_const_destruc(const std::string msg) const;
		
	public:
		Form();
		Form(const std::string name);
		Form(const int grSigned, const  int grExcecute);
		Form(const std::string name, const  int grSigned, const  int grExcecute);
		Form(const Form &copy);
		
		Form &operator=(const Form &src); 
	
		~Form();

		// Getter
		std::string getAllFormInformation() const;
		std::string getName() const;
		std::string getIsSigndedString() const;
		bool getIsSignded() const;
		int getGradeSigned() const;
		int getGradeExecute() const;

		// Setter 
		void setIsSignded(const bool isSignded);



		void beSigned(const Bureaucrat &person);
		
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

std::ostream &operator<<(std::ostream& os, const Form &form);

#endif