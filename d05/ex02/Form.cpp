#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(std::string const & target, std::string const & name, int sign, int exec)
	:_target(target), _name(name), _grade_to_sign(sign), _grade_to_execute(exec), _signature(false){

	if (this->_grade_to_sign <= 0 || this->_grade_to_execute <= 0)
		throw (GradeTooHighException());
	if (this->_grade_to_sign > 150 || this->_grade_to_execute > 150)
		throw (GradeTooLowException());
	return ;
}

Form::Form(Form const & src)
	:_name(src.getName()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute()){

	*this = src;
	return ;
}

Form::~Form(void){

	return ;
}

Form &	Form::operator=(Form const & rhs){

	if (this != &rhs)
	{
		this->_signature = rhs.getSignature();
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string const	Form::getName(void) const{

	return this->_name;
}

int	Form::getGradeToSign(void) const{

	return this->_grade_to_sign;
}

int	Form::getGradeToExecute(void) const{

	return this->_grade_to_execute;
}

std::string	Form::getTarget(void) const{

	return this->_target;
}

bool	Form::getSignature(void) const{

	return this->_signature;
}

void	Form::beSigned(Bureaucrat const & bureaucrat){

	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw (GradeTooLowException());
	this->_signature = true;
	return ;
}

void	Form::execute(Bureaucrat const & executor) const{

	if (this->_grade_to_execute < executor.getGrade())
		throw (GradeTooLowException());
	if (this->_signature == false)
		throw (UnsignedFormException());
	return ;
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs){

	o << "<" <<  std::boolalpha 
		<< rhs.getName() << "> form grade needed to sign <"
		<< rhs.getGradeToSign() << "> grade needed to execute <"
		<< rhs.getGradeToExecute() << "> signature status <"
		<< rhs.getSignature() << ">"
	<< std::endl;
	return o;
}
