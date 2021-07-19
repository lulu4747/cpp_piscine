#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void){

	return ;
}

AMateria::AMateria(AMateria const & src){

	*this = src;
	return ;
}

AMateria::AMateria(std::string const &type):type_(type){

	return ;
}

AMateria::~AMateria(void){

	return ;
}

AMateria &	AMateria::operator=(AMateria const &rhs){

	if (this != &rhs)
		this->type_ = rhs.getType();
	return *this;
}

std::string const &	AMateria::getType() const{

	return this->type_;
}

void AMateria::use(ICharacter &target){

	return ;
}