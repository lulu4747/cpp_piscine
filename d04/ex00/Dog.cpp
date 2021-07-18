#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void){

	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	return ;
}

Dog::~Dog(void){

	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const & src){

	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog &	Dog::operator=(Dog const & rhs){

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	Dog::makeSound(void) const{

	std::cout << "Dog is barking." << std::endl;
	return ;
}
