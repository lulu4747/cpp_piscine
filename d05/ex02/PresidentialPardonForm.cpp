#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string const & name):Form(name, 25, 5){

	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):Form(src.getName(), 25, 5){

	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void){

	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){

	this->Form::operator=(rhs);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & bureaucrat, std::string target){

	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());
	std::cout << "<" << target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}

