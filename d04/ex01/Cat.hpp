#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat : public Animal{

public:

	Cat(void);
	virtual ~Cat(void);
	Cat(Cat const & src);

	virtual Cat &	operator=(Cat const & rhs);

	virtual void	makeSound(void) const;

};

#endif
