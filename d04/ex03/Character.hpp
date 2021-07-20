#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class Character : public ICharacter{

public:

	Character(void);
	Character(std::string const & name);
	Character(Character const & src);
	virtual ~Character(void);

	Character & operator=(Character const & rhs);

	virtual std::string const & getName(void) const;
	size_t			getWeight(void) const;
	AMateria const*	getInventory(size_t i) const;

	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:

	std::string	_name;
	AMateria*	_inventory[4];
	size_t		_weight;

};

#endif
