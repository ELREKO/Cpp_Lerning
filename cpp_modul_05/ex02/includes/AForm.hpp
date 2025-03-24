

# ifndef AFORM_HPP
# define AFORM_HPP

# include "Header_Generally.hpp"
# include "Bureaucrat.hpp"


class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const  int _gradeSigned;
		const  int _gradeExecute;

		int tryToSetGrade(const  int grade) const;

		void msg_const_destruc(const std::string msg) const;
		
	public:
		AForm();
		AForm(const std::string name);
		AForm(const int grSigned, const  int grExcecute);
		AForm(const std::string name, const  int grSigned, const  int grExcecute);
		AForm(const AForm &copy);
		
		AForm &operator=(const AForm &src); 
	
		virtual ~AForm();

		// Getter
		std::string getAllAFormInformation() const;
		std::string getName() const;
		std::string getIsSigndedString() const;
		bool getIsSignded() const;
		int getGradeSigned() const;
		int getGradeExecute() const;

		// Setter 
		void setIsSignded(const bool isSignded);


		virtual void excute(Bureaucrat const &executor) const = 0;
		bool checkExcecutePossible(Bureaucrat const &executor, const std::string target) const;

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
		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, const AForm &form);

#endif