#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{

public:

	Dog(void);
	Dog(Dog const & src);
	virtual ~Dog(void);

	virtual Dog &	operator=(Dog const & rhs);

	virtual void	makeSound(void) const;
	virtual Brain*	getBrain(void) const;

private:

	Brain*	_brain;

};

#endif
