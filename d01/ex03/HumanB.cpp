#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name),_weapon(NULL){

	return ;
}

HumanB::~HumanB(void){

	return ;
}

void		HumanB::attack(void) const{

	std::cout << this->getName() << " attacks with his " << this->getWeaponType() << std::endl;
}

void		HumanB::setWeapon(Weapon weapon){

	this->_weapon = &weapon;
	return ;
}

std::string	HumanB::getName(void) const{

	return this->_name;
}

std::string	HumanB::getWeaponType(void) const{

	if (!this->_weapon)
		return "barre hands";
	return this->_weapon->getType();
}
