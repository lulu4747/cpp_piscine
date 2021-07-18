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

DiamondTrap::DiamondTrap(std::string const & name){

	std::cout << "DiamondTrap " << name << " initialisation constructor called" << std::endl;
	this->ClapTrap::setName(name + "_clap_name");
	this->_name = name;
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

void	DiamondTrap::attack(std::string const & target){

	this->ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::takeDamage(unsigned int amount){

	if (this->getHitpoints() == 0)
	{
		std::cout << "DiamondTrap " << this->_name	<< " cannot be attacked anymore"
					<< " ... He's in a trashcan ! x,@ " << std::endl;
		return ;
	}
	this->setHitpoints(this->getHitpoints() - amount);
	std::cout << "DiamondTrap " << this->_name
				<< " took " << amount << " points of damage ";
	if (this->getHitpoints() <= 0)
	{
		this->setHitpoints(0);
		std::cout << "and is now in a better place..." << std::endl;
	}
	else
	{
		std::cout << "and survived with "
			<< this->getHitpoints() << " HP left ! Did he deserve it ?" << std::endl;
	}
	return ;
}

void	DiamondTrap::beRepaired(unsigned int amount){

	this->setHitpoints(this->getHitpoints() + amount);
	std::cout << "DiamondTrap " << this->_name << " was repaired by "
				<< amount << " points ! He is left with " << this->getHitpoints()
				<< " HP. How long will he keep living like this ?..." << std::endl;
	return ;
}

std::string	DiamondTrap::getName(void) const{

	return this->_name;
}
