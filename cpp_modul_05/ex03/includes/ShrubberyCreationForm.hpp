

# ifndef SHRUBBERYFORM_HPP
# define SHRUBBERYFORM_HPP

# include "Header_Generally.hpp"
//# include "Bureaucrat.hpp"
# include "AForm.hpp"



class ShrubberyCreationForm:  virtual public AForm
{
	private:
		const std::string _target;
		ShrubberyCreationForm();

	public:
		// Constructor and Destructor 
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		// Getter 
		std::string getTarget();

		// Other Members
		void excute(Bureaucrat const &executor) const;
};



#endif