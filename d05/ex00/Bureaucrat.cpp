#include <iostream>
#include <string>
# include <stdexcept>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("Some random"),_grade(150){

	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade):_name(name),_grade(grade){

	if (this->_grade <= 0)
		throw (GradeTooHighException());
	if (this->_grade > 150)
		throw (GradeTooLowException());
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src):_name(src.getName()){

	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void){

	return ;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs){

	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::string const &	Bureaucrat::getName(void) const{

	return this->_name;
}

int	Bureaucrat::getGrade(void) const{

	return this->_grade;
}

void	Bureaucrat::upgrade(void){

	if (this->_grade - 1 <= 0)
		throw(GradeTooHighException());
	this->_grade--;
	return ;
}

void	Bureaucrat::downgrade(void){

	if (this->_grade + 1 > 150)
		throw(GradeTooLowException());
	this->_grade++;
	return ;
}
