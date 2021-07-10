#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void){

	return ;
}

Zombie::~Zombie(void){

	std::cout << "Zombie " << this->getName() << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void) const{

	std::cout << "<" << this->getName() << "> BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string	Zombie::getName(void) const{

	return this->_name;
}

void	Zombie::setName(std::string name){

	this->_name = name;
}