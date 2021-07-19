#include <iostream>
#include <string>
#include "Animal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void){

	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::~WrongCat(void){

	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const & src){

	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat &	WrongCat::operator=(WrongCat const & rhs){

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	WrongCat::makeSound(void) const{

	std::cout << "WrongCat is meowing." << std::endl;
	return ;
}
