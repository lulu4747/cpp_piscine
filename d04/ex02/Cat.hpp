#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{

public:

	Cat(void);
	virtual ~Cat(void);
	Cat(Cat const & src);

	virtual Cat &	operator=(Cat const & rhs);

	virtual void	makeSound(void) const;
	virtual Brain*	getBrain(void) const;

private:

	Brain*	_brain;

};

#endif
