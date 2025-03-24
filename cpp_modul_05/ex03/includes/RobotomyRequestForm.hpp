# ifndef ROBOTFORM_HPP
# define ROBOTFORM_HPP

# include "Header_Generally.hpp"
//# include "Bureaucrat.hpp"
# include "AForm.hpp"



class RobotomyRequestForm:  virtual public AForm
{
	private:
		const std::string _target;
		RobotomyRequestForm();

	public:
		// Constructor and Destructor 
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		// Getter 
		std::string getTarget();

		// Other Members
		void excute(Bureaucrat const &executor) const;
};

#endif