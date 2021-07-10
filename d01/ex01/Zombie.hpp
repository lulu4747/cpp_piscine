#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

public :

	Zombie(void);
	~Zombie(void);

	void	announce(void) const;

	std::string	getName(void) const;
	void		setName(std::string name);

private :

	std::string	_name;
};

Zombie* ZombieHorde(int N, std::string name);

#endif
