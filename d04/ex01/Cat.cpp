#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void){

	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	return ;
}

Cat::~Cat(void){

	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const & src){

	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat &	Cat::operator=(Cat const & rhs){

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	Cat::makeSound(void) const{

	std::cout << "Cat is meowing." << std::endl;
	return ;
}
