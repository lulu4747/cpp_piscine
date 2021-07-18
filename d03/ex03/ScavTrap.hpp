#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap{

public:

	ScavTrap(void);
	ScavTrap(std::string const & name);
	~ScavTrap(void);
	ScavTrap(ScavTrap const & src);

	ScavTrap &	operator=(ScavTrap const & rhs);

	void	guardGate(void);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:

	bool	_GateKeeping;

};

#endif
