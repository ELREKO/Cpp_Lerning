# include "includes/Bureaucrat.hpp"
# include "includes/Form.hpp"

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

	Form* Bauantrag = new Form( 100, 11);
	std::cout << *Bauantrag <<  std::endl;
	
	Bauantrag->beSigned(empl1);
	Bauantrag->beSigned(*empl2);
	Bauantrag->beSigned(*empl2);

	Form Zollfreiheit("Zoll", 12, 13);
	Bauantrag->beSigned(empl1);
	empl2->signForm(Zollfreiheit);
	empl2->signForm(Zollfreiheit);


	std::cout 	<<std::endl;

	delete empl2;
	delete Bauantrag;
}