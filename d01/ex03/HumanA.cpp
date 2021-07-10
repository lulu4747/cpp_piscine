#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):_name(name), _weapon(weapon){

	return ;
}

HumanA::~HumanA(void){

	return ;
}

void		HumanA::attack(void) const{

	std::cout << this->getName() << " attacks with his " << this->getWeaponType() << std::endl;
}

std::string	HumanA::getName(void) const{

	return this->_name;
}

std::string	HumanA::getWeaponType(void) const{

	return this->_weapon.getType();
}
