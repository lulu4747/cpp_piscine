#include "Weapon.hpp"

Weapon::Weapon(std::string const& type):_type(type){

	return ;
}

Weapon::~Weapon(void){

	return ;
}

std::string&	Weapon::getType(void){

	return this->_type;
}
void			Weapon::setType(std::string const& type){

	this->_type = type;
	return ;
}