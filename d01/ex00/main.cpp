#include "Zombie.hpp"

int	main(void){

	Zombie*	ben;

	randomChump("Bob (on stack)");
	ben = newZombie("Ben (on heap)");
	ben->announce();
	delete ben;
	return 0;
}