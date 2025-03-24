//# include "includes/Bureaucrat.hpp"
//# include "includes/AForm.hpp"
# include "includes/Intern.hpp"

int main()
{
	std::string formName[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	Intern inter;
	AForm *form;
	//form = inter.makeForm(formName[1], "Frau Holle");
	form = inter.makeForm("Noise", "Frau Holle");

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

	AForm* Bauantrag;
	Bauantrag = inter.makeForm(formName[0], "Frau Holle");

	std::cout << Bauantrag <<  std::endl;
	
	Bauantrag->beSigned(empl1);
	Bauantrag->beSigned(*empl2);
	Bauantrag->beSigned(*empl2);
	Bauantrag->beSigned(empl1);

	AForm* Zollfreiheit;
	Zollfreiheit = inter.makeForm(formName[2], "Rot käppchen");
	
	empl2->signForm(*Zollfreiheit);
	empl2->signForm(*Zollfreiheit);


	AForm* Zwerg;
	Zwerg = inter.makeForm(formName[2], "Schneewitchen");

	Zwerg->beSigned(empl1);
	Zwerg->beSigned(*empl2);


	// --------------------- ex02 ------------------
	std::cout 	<<std::endl <<std::endl
				<< "----------------------ex02-----------------------"
				<<std::endl <<std::endl;
	
	Bauantrag->excute(empl1);
	empl1.executeForm(*Bauantrag);
	Bauantrag->excute(*empl2);
	Zollfreiheit->excute(*empl2);
	empl1.executeForm(*Zwerg);

	// --------------------- ex02 ------------------
	std::cout 	<<std::endl <<std::endl
				<< "----------------------ex02-----------------------"
				<<std::endl <<std::endl;

	AForm* Test;
	Test = inter.makeForm("Noting", "Rosenrot");
	std::cout << Test << std::endl;


	std::cout 	<<std::endl;

	delete empl2;
	delete Zwerg;
	delete Bauantrag;
	delete Zollfreiheit;
	delete Test;

}