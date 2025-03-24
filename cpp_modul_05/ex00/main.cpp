# include "includes/Bureaucrat.hpp"



int main()
{
	Bureaucrat *empl1 = new Bureaucrat("Carl", 160);
	Bureaucrat *empl2 = new Bureaucrat("Max", -12);
	std::cout << std::endl << *empl1 << std::endl ;
	std::cout << std::endl << *empl2 << std::endl ;
	empl1->decrementGrade();
	empl1->incrementGrade();

	std::cout <<std::endl <<std::endl;
	empl2->incrementGrade();
	empl2->decrementGrade();
	delete empl1;
	delete empl2;
	// empl1->incrementGrade();
	// empl1->incrementGrade();
	// std::cout << empl1->getGrade() << std::endl;
	// std::cout << empl1->getName() << std::endl;
	// std::cout << std::endl << *empl1 << std::endl << std::endl ;
	// delete empl1;

	// Bureaucrat empl2("Max", 1);
	// Bureaucrat empl3(empl2);

	// std::cout << std::endl << empl2 << std::endl << std::endl ;
	// std::cout << std::endl << empl3 << std::endl << std::endl ;

	// empl2.decrementGrade();
	// empl2.decrementGrade();
	// empl3 = empl2;

	// std::cout << std::endl << empl3 << std::endl << std::endl ;
	// empl2.decrementGrade();
	// empl2.incrementGrade();
	// empl2.incrementGrade();
	// empl2.incrementGrade();
	// std::cout << empl2.getGrade() << std::endl;
	// std::cout << empl2.getName() << std::endl;

}