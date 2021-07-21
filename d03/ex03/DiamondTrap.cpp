#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){

	std::cout << "DiamondTrap <unnamed> default constructor called" << std::endl;
	this->_name = "";
	this->setHitpoints(this->FragTrap::getHitpoints());
	this->setEnergyPoints(this->ScavTrap::getEnergyPoints());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string const & name):ClapTrap(name + "_clap_name"), _name(name){

	std::cout << "DiamondTrap " << name << " initialisation constructor called" << std::endl;
	this->setHitpoints(this->FragTrap::getHitpoints());
	this->setEnergyPoints(this->ScavTrap::getEnergyPoints());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
	return ;
}

DiamondTrap::~DiamondTrap(void){

	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src){

	std::cout << "DiamondTrap " << src.getName() << " copy constructor called" << std::endl;
	*this = src;
	return ;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhs){

	if (this != &rhs)
	{
		this->ClapTrap::setName(rhs.ClapTrap::getName());
		this->setName(rhs.getName());
		this->setHitpoints(rhs.getHitpoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

void	DiamondTrap::whoAmI(void){

	std::cout << "Is this DiamondTrap " << this->_name << " or is it " << this->ClapTrap::getName() << " ?" << std::endl;
	return ;
}

std::string	DiamondTrap::getName(void) const{

	return this->_name;
}
