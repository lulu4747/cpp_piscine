#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string const & target):Form(target, "RobotomyRequestForm", 72, 45){

	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):Form(src.getTarget(), src.getName(), 72, 45){

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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{

	Form::execute(executor);

	std::srand(std::time(nullptr));
	std::cout << "* Some drilling noises *" << std::endl << "<" << this->getTarget() << ">";
	if (std::rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << "'s robotomy failed" << std::endl;

	return ;
}