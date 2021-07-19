#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal(void):type(""){

	std::cout << "Animal default constructor called" << std::endl;
	return ;
}
Animal::~Animal(void){

	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const & src){

	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return ;
}

Animal &	Animal::operator=(Animal const & rhs){

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::string	Animal::getType(void) const{

	return this->type;
}

void	Animal::setType(std::string str){

	this->type = str;
	return ;
}
