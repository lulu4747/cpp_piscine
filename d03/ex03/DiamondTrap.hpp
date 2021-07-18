#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap{

public:

	DiamondTrap(void);
	DiamondTrap(std::string const & name);
	~DiamondTrap(void);
	DiamondTrap(DiamondTrap const & src);

	DiamondTrap &	operator=(DiamondTrap const & rhs);

	void	whoAmI(void);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName(void) const;

private:

	std::string	_name;

};

#endif
