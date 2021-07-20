#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
	
Cure::Cure(void):AMateria("cure"){

	return ;
}

Cure::Cure(Cure const & src):AMateria("cure"){

	(void)src;
	return ;
}

Cure::~Cure(void){

	return ;
}

Cure &	Cure::operator=(Cure const & rhs){

	(void)rhs;
	return *this;
}

Cure* Cure::clone() const{

	Cure*	new_cure = new Cure();

	return new_cure;
}

void Cure::use(ICharacter& target){

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
