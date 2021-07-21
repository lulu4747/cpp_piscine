#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap{

public:

	ScavTrap(std::string const & name);
	~ScavTrap(void);
	ScavTrap(ScavTrap const & src);

	ScavTrap &	operator=(ScavTrap const & rhs);

	void	guardGate(void);
	void	attack(std::string const & target);

	bool	getKeeping(void) const;

protected:

	ScavTrap(void);

private:

	bool	_GateKeeping;

};

#endif
