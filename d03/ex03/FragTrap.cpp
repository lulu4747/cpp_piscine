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

FragTrap::FragTrap(std::string const & name){

	std::cout << "FragTrap " << name << " initialisation constructor called" << std::endl;
	this->setName(name);
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

void	FragTrap::attack(std::string const & target){

	std::cout << "FragTrap " << this->getName() << " attacks "
				<< target << " with skill causing " << this->getAttackDamage()
				<< " points of damage !" << std::endl;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount){

	if (this->getHitpoints() == 0)
	{
		std::cout << "FragTrap " << this->getName()	<< " cannot be attacked anymore"
					<< " ... He's in pieces ! x,@ " << std::endl;
		return ;
	}
	this->setHitpoints(this->getHitpoints() - amount);
	std::cout << "FragTrap " << this->getName()
				<< " took " << amount << " points of damage ";
	if (this->getHitpoints() <= 0)
	{
		this->setHitpoints(0);
		std::cout << "and is now sleeping (dead)..." << std::endl;
	}
	else
	{
		std::cout << "and survived with "
			<< this->getHitpoints() << " HP left ! It hurts !" << std::endl;
	}
	return ;
}

void	FragTrap::beRepaired(unsigned int amount){

	this->setHitpoints(this->getHitpoints() + amount);
	std::cout << "FragTrap " << this->getName() << " was repaired by "
				<< amount << " points ! He is left with " << this->getHitpoints()
				<< " HP. Sweet !" << std::endl;
	return ;
}
