#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria{

public:

	AMateria(void);
	AMateria(AMateria const & src);
	AMateria(std::string const & type);
	virtual ~AMateria(void);

	AMateria &	operator=(AMateria const & rhs);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:

	std::string	type_;

};

#endif
