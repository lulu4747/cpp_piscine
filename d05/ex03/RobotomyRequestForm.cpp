#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain(void){

	std::cout << "Brain default constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = "";
	return ;
}

Brain::Brain(Brain const & src){

	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain(void){

	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain &	Brain::operator=(Brain const & rhs){

	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdea(i);
	}
	return *this;
}

std::string	Brain::getIdea(size_t index) const{

	return this->_ideas[index];
}

void	Brain::setIdea(size_t index, std::string str){

	this->_ideas[index] = str;
	return ;
}