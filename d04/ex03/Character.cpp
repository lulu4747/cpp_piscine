#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(void):_name("Stranger"){

	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string const & name):_name(name),_weight(0){

	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(Character const & src){

	*this = src;
	return ;
}

Character::~Character(){

	return ;
}

Character &	Character::operator=(Character const & rhs){

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_weight = rhs.getWeight();
		this->_inventory[0] == rhs.getInventory(0);
		this->_inventory[1] == rhs.getInventory(1);
		this->_inventory[2] == rhs.getInventory(2);
		this->_inventory[3] == rhs.getInventory(3);
	}
	return *this;
}

void	Character::equip(AMateria* m){

	if (this->_weight == 4)
		return ;
	this->_inventory[this->_weight] = m;
	this->_weight++;
	return ;
}

void	Character::unequip(int idx){

	this->_inventory[idx] = NULL;
	return ;
}

size_t	Character::getWeight(void) const{

	return this->_weight;
}

AMateria const*	Character::getInventory(size_t i) const{

	return this->_inventory[i];
}

void Character::use(int idx, ICharacter& target){

	this->_inventory[idx]->use(target);
}
