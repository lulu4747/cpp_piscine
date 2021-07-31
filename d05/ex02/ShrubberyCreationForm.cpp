#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const & name):Form(name, 145, 137){

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):Form(src.getName(), 145, 137){

	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){

	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){

	this->Form::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat, std::string target){

	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());
	std::cout << "<" << target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}
