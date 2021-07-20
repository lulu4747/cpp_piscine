#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void):_learned(0){

	for (size_t i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src){

	*this = src;
	return ;
}

MateriaSource::~MateriaSource(){

	return ;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs){

	if (this != &rhs)
	{
		this->_learned = rhs.getLearned();
		this->_materia[0] == rhs.getMateria(0);
		this->_materia[1] == rhs.getMateria(1);
		this->_materia[2] == rhs.getMateria(2);
		this->_materia[3] == rhs.getMateria(3);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia){

	if (this->_learned == 4)
		return ;
	this->_materia[this->_learned] = materia;
	this->_learned++;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type){

	for (size_t i = 0; i < this->_learned; i++)
	{
		if (type.compare(this->_materia[i]->getType()))
			return this->_materia[i];
	}
	return NULL;
}

size_t	MateriaSource::getLearned(void) const{

	return this->_learned;
}

AMateria const *	MateriaSource::getMateria(size_t i) const{

	return this->_materia[i];
}
