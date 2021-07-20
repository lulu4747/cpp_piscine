#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void):_learned(0){

	for (size_t i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src):_learned(0){

	*this = src;
	return ;
}

MateriaSource::~MateriaSource(){

	for (size_t i = 0; i < this->_learned; i++)
		delete this->_materia[i];
	return ;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs){

	if (this != &rhs)
	{
		for (size_t i = 0; i < this->_learned; i++)
			delete this->_materia[i];
		this->_learned = rhs.getLearned();
		if (this->_learned > 0)
		{
			for (size_t i = 0; i < 4; i++)
				this->_materia[i] = rhs.getMateria(i)->clone();
		}
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
		if (!(type.compare(this->_materia[i]->getType())))
			return this->_materia[i]->clone();
	}
	return NULL;
}

size_t	MateriaSource::getLearned(void) const{

	return this->_learned;
}

AMateria const *	MateriaSource::getMateria(size_t i) const{

	return this->_materia[i];
}
