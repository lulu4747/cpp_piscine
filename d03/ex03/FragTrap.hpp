#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{

public:

	FragTrap(std::string const & name);
	~FragTrap(void);
	FragTrap(FragTrap const & src);

	FragTrap &	operator=(FragTrap const & rhs);

	void	highFivesGuys(void);

protected:

	FragTrap(void);
};

#endif
