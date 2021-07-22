#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(void):_name("Stranger"),_weight(0){

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

	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	return ;
}

Character &	Character::operator=(Character const & rhs){

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		for (size_t i = 0; i < this->_weight; i++)
			delete this->_inventory[i];
		this->_weight = rhs.getWeight();
		if (this->_weight > 0)
		{
			for (size_t i = 0; i < 4; i++)
				this->_inventory[i] = rhs.getInventory(i)->clone();
		}
	}
	return *this;
}

void	Character::equip(AMateria* m){

	if (this->_weight == 4)
		return ;
	for (size_t i = 0; i <= this->_weight; i++)
	{
		if (!this->_inventory[i])
			this->_inventory[i] = m;
	}
	this->_weight++;
	return ;
}

void	Character::unequip(int idx){

	if (this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = NULL;
		this->_weight--;
	}
	return ;
}

std::string const & Character::getName(void) const{

	return this->_name;
}

size_t	Character::getWeight(void) const{

	return this->_weight;
}

AMateria const*	Character::getInventory(size_t i) const{

	if (i >= 0 && i <= this->_weight)
		return this->_inventory[i];
	return NULL;
}

void Character::use(int idx, ICharacter& target){

	if (idx >= 0 && idx <= (int)this->_weight)
		this->_inventory[idx]->use(target);
	return ;
}
