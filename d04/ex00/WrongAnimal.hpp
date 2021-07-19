#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal{

public:

	WrongAnimal(void);
	~WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);

	WrongAnimal &	operator=(WrongAnimal const & rhs);

	void		makeSound(void) const;
	
	std::string	getType(void) const;

protected:

	std::string	type;

};

#endif
