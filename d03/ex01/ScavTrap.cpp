#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){

	std::cout << "ScavTrap <unnamed> default constructor called" << std::endl;
	this->setHitpoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string const & name):ClapTrap(name),_GateKeeping(false){

	std::cout << "ScavTrap " << name << " initialisation constructor called" << std::endl;
	this->setHitpoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return ;
}

ScavTrap::~ScavTrap(void){

	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src){

	std::cout << "ScavTrap " << src.getName() << " copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs){

	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->_GateKeeping = rhs.getKeeping();
		this->setHitpoints(rhs.getHitpoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

void	ScavTrap::guardGate(void){

	if (!this->_GateKeeping)
	{
		std::cout << "ScavTrap " << this->getName() << " is now guarding the Gate !" << std::endl;
		this->_GateKeeping = true;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " is not guarding the Gate anymore !" << std::endl;
		this->_GateKeeping = false;
	}
	return ;
}

void	ScavTrap::attack(std::string const & target){

	std::cout << "ScavTrap " << this->getName() << " attacks "
				<< target << " with violence causing " << this->getAttackDamage()
				<< " points of damage !" << std::endl;
	return ;
}

bool	ScavTrap::getKeeping(void) const{

	return this->_GateKeeping;
}
