#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Dog.hpp"
# include "Brain.hpp"

Dog::Dog(void){

	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(Dog const & src){

	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
	return ;
}

Dog::~Dog(void){

	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return ;
}

Dog &	Dog::operator=(Dog const & rhs){

	if (this != &rhs)
	{
		*this->_brain = *rhs.getBrain();
		this->type = rhs.getType();
	}
	return *this;
}

void	Dog::makeSound(void) const{

	std::cout << "Dog is barking." << std::endl;
	return ;
}

Brain*	Dog::getBrain(void) const{

	return this->_brain;
}
