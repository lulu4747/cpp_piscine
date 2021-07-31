#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string const & name):Form(name, 72, 45){

	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):Form(src.getName(), 72, 45){

	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void){

	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){

	this->Form::operator=(rhs);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & bureaucrat, std::string target){

	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());
	std::cout << "<" << target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}