#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

public:

	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	virtual ~MateriaSource(void);

	MateriaSource &	operator=(MateriaSource const & rhs);

	virtual void		learnMateria(AMateria* materia);
	virtual AMateria*	createMateria(std::string const & type);

	size_t				getLearned(void) const;
	AMateria const *	getMateria(size_t i) const;

private:

	AMateria *	_materia[4];
	size_t		_learned;
};

#endif