#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{

public:

	Weapon(std::string const& type);
	~Weapon(void);

	std::string&	getType(void);
	void			setType(std::string const& type);

private:

	std::string	_type;

};

#endif
