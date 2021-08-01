#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	Bureaucrat Joel("Joel", 1);
	Form*	test;

	for (int i = 0; i < 3; i++)
	{
		if (i == 0){
			std::cout << "---------------------------------------------------------------------" << std::endl
				<< "PresidentialPardonForm :" << std::endl;
			test = new PresidentialPardonForm("President");
		}
		else if (i == 1){
			std::cout << "---------------------------------------------------------------------" << std::endl
				<< "RobotomyRequestForm :" << std::endl;
			test = new RobotomyRequestForm("Robot");
		}
		else{
			std::cout << "---------------------------------------------------------------------" << std::endl
				<< "ShrubberyCreationForm :" << std::endl;
			test = new ShrubberyCreationForm("Tree");
		}

		Joel = Bureaucrat("Joel", test->getGradeToSign() + 1);

		for (int j = 0; j < 2; j++)
		{

			std::cout << std::endl << std::endl << *test << Joel << std::endl << std::endl;

			Joel.signForm(*test);
			try
			{
				test->beSigned(Joel);
			}
			catch(const std::exception & e)
			{
				std::cerr << e.what() << std::endl;
			}

			Joel.executeForm(*test);
			try
			{
				test->execute(Joel);
			}
			catch(const std::exception & e)
			{
				std::cerr << e.what() << std::endl;
			}

			Joel.upgrade();

		}

		Joel = Bureaucrat("Joel", test->getGradeToExecute());
		std::cout << std::endl << std::endl << *test << Joel << std::endl << std::endl;

		Joel.executeForm(*test);
		try
		{
			test->execute(Joel);
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		delete test;
	}
	return 0;
}
