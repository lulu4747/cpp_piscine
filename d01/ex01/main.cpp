#include "Zombie.hpp"

int	main(void){

	Zombie*	zombies = ZombieHorde(5, "George");

	zombies->announce();
	delete [] zombies;
	return 0;
}