#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap{

public:

	ClapTrap(std::string const & name);
	~ClapTrap(void);
	ClapTrap(ClapTrap const & src);

	ClapTrap &	operator=(ClapTrap const & rhs);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string const &	getName(void) const;
	int				getHitpoints(void) const;
	int				getEnergyPoints(void) const;
	int				getAttackDamage(void) const;

	void	setName(std::string const & name);
	void	setHitpoints(int const amount);
	void	setEnergyPoints(int const amount);
	void	setAttackDamage(int const amount);

protected:

	ClapTrap(void);

	std::string			_name;
	int					_Hitpoints;
	int					_EnergyPoints;
	int					_AttackDamage;

};

#endif
