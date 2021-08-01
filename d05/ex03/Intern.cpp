#include <iostream>
#include <string>
#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void){

	this->_type[0] = "PresidentialPardonForm";
	this->_make[0] = &Intern::makePresidentialPardonForm;
	this->_type[1] = "RobotomyRequestForm";
	this->_make[1] = &Intern::makeRobotomyRequestForm;
	this->_type[2] = "ShrubberyCreationForm";
	this->_make[2] = &Intern::makeShrubberyCreationForm;
	return ;
}

Intern::~Intern(void){

	return ;
}

Form*	Intern::makeForm(std::string const & name, std::string const & target){

	for (int i = 0; i < 3; i++)
	{
		if (this->_type[i].compare(name) == 0)
		{
			std::cout << "Intern creates <" << name << ">" << std::endl;
			return (this->*_make[i])(target);
		}
	}
	std::cout << "Intern cannot create <" << name << "> because it is unknown" << std::endl;
	return NULL;
}

Form*	Intern::makePresidentialPardonForm(std::string const & target){

	return new PresidentialPardonForm(target);
}

Form*	Intern::makeRobotomyRequestForm(std::string const & target){

	return new RobotomyRequestForm(target);
}

Form*	Intern::makeShrubberyCreationForm(std::string const & target){

	return new ShrubberyCreationForm(target);
}