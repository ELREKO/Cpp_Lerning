//# include "includes/Bureaucrat.hpp"
//# include "includes/AForm.hpp"
# include "includes/ShrubberyCreationForm.hpp"
# include "includes/RobotomyRequestForm.hpp"
# include "includes/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat empl1("Carl", 160);
	Bureaucrat *empl2 = new Bureaucrat("Max", -12);
	std::cout << std::endl << empl1 << std::endl ;
	std::cout << std::endl << *empl2 << std::endl ;
	empl1.decrementGrade();
	empl1.incrementGrade();

	std::cout <<std::endl <<std::endl;
	empl2->incrementGrade();
	empl2->decrementGrade();

	// --------------------- ex01 ------------------
	std::cout 	<<std::endl <<std::endl
				<< "----------------------ex01-----------------------"
				<<std::endl <<std::endl;

	AForm* Bauantrag = new ShrubberyCreationForm("Frau Holle");
	std::cout << *Bauantrag <<  std::endl;
	
	Bauantrag->beSigned(empl1);
	Bauantrag->beSigned(*empl2);
	Bauantrag->beSigned(*empl2);

	RobotomyRequestForm Zollfreiheit("Rotkäppchen");
	Bauantrag->beSigned(empl1);
	empl2->signForm(Zollfreiheit);
	empl2->signForm(Zollfreiheit);

	AForm* Zwerg = new PresidentialPardonForm("Schneewitchen");
	Zwerg->beSigned(empl1);
	Zwerg->beSigned(*empl2);




	// --------------------- ex02 ------------------
	std::cout 	<<std::endl <<std::endl
				<< "----------------------ex03-----------------------"
				<<std::endl <<std::endl;
	
	Bauantrag->excute(empl1);
	empl1.executeForm(*Bauantrag);
	Bauantrag->excute(*empl2);
	Zollfreiheit.excute(*empl2);
	empl1.executeForm(*Zwerg);




	std::cout 	<<std::endl;

	delete empl2;
	delete Zwerg;
	delete Bauantrag;
}