#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA{

public :

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void		attack(void) const;
	std::string	getName(void) const;
	std::string	getWeaponType(void) const;

private :

	std::string const _name;
	Weapon&		_weapon;

};

#endif
