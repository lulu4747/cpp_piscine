#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void){

	std::cout << "FragTrap <unnamed> default constructor called" << std::endl;
	this->setHitpoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string const & name):ClapTrap(name){

	std::cout << "FragTrap " << name << " initialisation constructor called" << std::endl;
	this->setHitpoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

FragTrap::~FragTrap(void){

	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src){

	std::cout << "FragTrap " << src.getName() << " copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs){

	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitpoints(rhs.getHitpoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

void	FragTrap::highFivesGuys(void){

	std::cout << "FragTrap " << this->getName() << " wants to execute an highfive !" << std::endl;
	return ;
}
