# ifndef PRESIDENTFORM_HPP
# define PRESIDENTFORM_HPP

# include "Header_Generally.hpp"
//# include "Bureaucrat.hpp"
# include "AForm.hpp"



class PresidentialPardonForm:  virtual public AForm
{
	private:
		const std::string _target;
		PresidentialPardonForm();

	public:
		// Constructor and Destructor 
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		// Getter 
		std::string getTarget();

		// Other Members
		void excute(Bureaucrat const &executor) const;
};

#endif