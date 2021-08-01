#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string const & target):Form(target, "PresidentialPardonForm", 25, 5){

	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):Form(src.getTarget(), src.getName(), 25, 5){

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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{

	Form::execute(executor);
	std::cout << "<" << this->getTarget() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}

