#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void){

	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::~Cat(void){

	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return ;
}

Cat::Cat(Cat const & src){

	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat &	Cat::operator=(Cat const & rhs){

	if (this != &rhs)
	{
		delete this->_brain;
		this->_brain = new Brain(*rhs.getBrain());
		this->type = rhs.getType();
	}
	return *this;
}

void	Cat::makeSound(void) const{

	std::cout << "Cat is meowing." << std::endl;
	return ;
}

Brain*	Cat::getBrain(void) const{

	return this->_brain;
}
