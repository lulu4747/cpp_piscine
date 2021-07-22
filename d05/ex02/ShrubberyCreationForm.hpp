#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal{

public:

	AAnimal(void);
	virtual	~AAnimal(void);
	AAnimal(AAnimal const & src);

	virtual AAnimal &	operator=(AAnimal const & rhs);

	virtual void		makeSound(void) const = 0;
	
	std::string	getType(void) const;
	void		setType(std::string str);

protected:

	std::string	type;

};

#endif
