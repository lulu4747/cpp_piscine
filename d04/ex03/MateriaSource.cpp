#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void):_learned(false){

	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src){

	*this = src;
	return ;
}

MateriaSource::~MateriaSource(){

	if 
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs){

	if (this != &rhs && rhs.hasLearned() == true)
	{
		this->_learned = true;
		for (t_mem *mem = rhs.getMem(); mem != NULL; mem = mem->next)
		{
			this->_mem = new t_mem;
			this->_mem->_type = mem->_type;
			this->_mem->_materia = new &(AMateria(*rhs.getMateria(mem->_type)));
			this->_mem->next = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* new_m){}

AMateria*	MateriaSource::createMateria(std::string const & type){}

AMateria*	MateriaSource::getMateria(std::string const & type) const{

	t_mem*	mem = this->_mem;

	while (mem && type.compare(mem->_type))
		mem = mem->next;
	return mem->_materia;
}

bool const & MateriaSource::hasLearned(void) const{

	return	this->_learned;
}