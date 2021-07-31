#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {							//Ajouter proprement execute methods (+ in base form class) en relisant bien le sujet

	Bureaucrat Joel("Joel", 1);
	Form*	test;

	for (int i = 0; i < 3; i++)
	{
		if (i == 0){
			std::cout << "PresidentialPardonForm :" << std::endl;
			test = new PresidentialPardonForm("test");
		}
		else if (i == 1){
			std::cout << "RobotomyRequestForm :" << std::endl;
			test = new RobotomyRequestForm("test");
		}
		else{
			std::cout << "ShrubberyCreationForm :" << std::endl;
			test = new ShrubberyCreationForm("test");
		}

		std::cout << *test << std::endl;
	
		Joel = Bureaucrat("Joel", test->getGradeToSign() + 1);

		Joel.signForm(*test);
		try{
		test->beSigned(Joel);}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';}

		std::cout << *test << std::endl;

		Joel.upgrade();

		Joel.signForm(*test);
		try{
		test->beSigned(Joel);}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';}

		std::cout << *test << std::endl << std::endl << std::endl;

		delete test;
	}
	return 0;
}
