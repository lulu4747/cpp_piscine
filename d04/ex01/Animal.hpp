#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal{

public:

	Animal(void);
	virtual	~Animal(void);
	Animal(Animal const & src);

	virtual Animal &	operator=(Animal const & rhs);

	virtual void		makeSound(void) const;
	
	std::string	getType(void) const;
	void		setType(std::string str);

protected:

	std::string	type;

};

#endif
