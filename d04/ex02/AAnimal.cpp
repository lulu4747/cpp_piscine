#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal(void):type(""){

	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}
AAnimal::~AAnimal(void){

	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & src){

	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
	return ;
}

AAnimal &	AAnimal::operator=(AAnimal const & rhs){

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::string	AAnimal::getType(void) const{

	return this->type;
}

void	AAnimal::setType(std::string str){

	this->type = str;
	return ;
}
