#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB{

public :

	HumanB(std::string name);
	~HumanB(void);

	void		attack(void) const;
	void		setWeapon(Weapon& weapon);
	std::string	getName(void) const;
	std::string	getWeaponType(void) const;

private :

	std::string const _name;
	Weapon*		_weapon;

};

#endif
