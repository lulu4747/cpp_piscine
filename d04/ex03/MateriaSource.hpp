#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource{

public:

	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	virtual ~MateriaSource();

	virtual MateriaSource &	operator=(MateriaSource const & rhs);

	virtual void learnMateria(AMateria* new_m);
	virtual AMateria* createMateria(std::string const & type);

	bool const &	hasLearned(void) const;
	AMateria*		MateriaSource::getMateria(std::string const & type) const;

private:

	typedef struct s_mem{
		std::string	_type;
		AMateria*	_materia;
		s_mem*		next;
	}	t_mem;

	t_mem*			_mem;
	bool			_learned;

};

#endif