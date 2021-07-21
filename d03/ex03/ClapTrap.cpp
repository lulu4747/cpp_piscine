#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name(""),_Hitpoints(10),_EnergyPoints(10),_AttackDamage(0){

	std::cout << "ClapTrap <unnamed> default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const & name):_name(name), _Hitpoints(10),_EnergyPoints(10),_AttackDamage(0){

	std::cout << "ClapTrap" << this->_name << " initialisation constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void){

	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src){

	std::cout << "ClapTrap" << src.getName() << " copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs){

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_Hitpoints = rhs.getHitpoints();
		this->_EnergyPoints = rhs.getEnergyPoints();
		this->_AttackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void ClapTrap::attack(std::string const & target){

	std::cout << "ClapTrap " << this->_name << " attacks "
				<< target << " causing " << this->_AttackDamage
				<< " points of damage !" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount){

	if (this->_Hitpoints == 0)
	{
		std::cout << "ClapTrap " << this->_name	<< " cannot be attacked anymore"
					<< " ... He's dead ! x,@ " << std::endl;
		return ;
	}
	this->_Hitpoints -= amount;
	std::cout << "ClapTrap " << this->_name
				<< " took " << amount << " points of damage ";
	if (this->_Hitpoints <= 0)
	{
		this->_Hitpoints = 0;
		std::cout << "and died ! :O" << std::endl;
	}
	else
	{
		std::cout << "and survived with "
			<< this->_Hitpoints << " HP left !" << std::endl;
	}
	return ;
}

void ClapTrap::beRepaired(unsigned int amount){

	this->_Hitpoints += amount;
	std::cout << "ClapTrap " << this->_name << " was repaired by "
				<< amount << " points ! He is left with " << this->_Hitpoints
				<< " HP. Yay !" << std::endl;
	return ;
}

std::string const &	ClapTrap::getName(void) const{

	return this->_name;
}

int	ClapTrap::getHitpoints(void) const{

	return this->_Hitpoints;
}

int	ClapTrap::getEnergyPoints(void) const{

	return this->_EnergyPoints;
}

int	ClapTrap::getAttackDamage(void) const{

	return this->_AttackDamage;
}

void	ClapTrap::setName(std::string const & name){

	this->_name = name;
	return ;
}

void	ClapTrap::setHitpoints(int const amount){

	this->_Hitpoints = amount;
	return ;
}

void	ClapTrap::setEnergyPoints(int const amount){

	this->_EnergyPoints = amount;
	return ;
}

void	ClapTrap::setAttackDamage(int const amount){

	this->_AttackDamage = amount;
	return ;
}
