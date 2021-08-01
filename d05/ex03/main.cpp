#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {

	Bureaucrat	Zafod("Zafod", 1);
	Intern		slave;
	Form*		test;

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
			case 0 : test = slave.makeForm("PresidentialPardonForm", "someone important");
				break;
			case 1 : test = slave.makeForm("RobotomyRequestForm", "slave");
				break;
			case 2 : test = slave.makeForm("ShrubberyCreationForm", "here");
				break;
		}
		Zafod.signForm(*test);
		Zafod.executeForm(*test);
		delete test;
	}
	return 0;
}
