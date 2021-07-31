#include <iostream>
#include <string>
#include <cstdlib>
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

void	RobotomyRequestForm::execute(Bureaucrat const & bureaucrat, std::string const & target) const{

	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());

	std::cout << "* Some drilling noises *" << std::endl << "<" << target << ">";
	if (std::rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << "'s robotomy failed" << std::endl;

	return ;
}