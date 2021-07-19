#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):type(""){

	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}
WrongAnimal::~WrongAnimal(void){

	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){

	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs){

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const{

	std::cout << "WrongAnimal is ... what is it called again ?" << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const{

	return this->type;
}
