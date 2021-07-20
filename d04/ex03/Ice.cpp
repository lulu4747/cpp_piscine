#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
	
Ice::Ice(void):AMateria("ice"){

	return ;
}

Ice::Ice(Ice const & src):AMateria("ice"){

	(void)src;
	return ;
}

Ice::~Ice(void){

	return ;
}

Ice &	Ice::operator=(Ice const & rhs){

	(void)rhs;
	return *this;
}

Ice* Ice::clone() const{

	Ice*	new_ice = new Ice();

	return new_ice;
}

void Ice::use(ICharacter& target){

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
