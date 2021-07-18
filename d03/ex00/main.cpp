#include "ClapTrap.hpp"

int main(void) {
	
	ClapTrap	R2("R2D2");

	R2.attack("C3");
	R2.takeDamage(5);
	R2.beRepaired(2);
	R2.takeDamage(8);
	R2.takeDamage(5);
	R2.beRepaired(2);
	R2.takeDamage(1);
	R2.takeDamage(1);
	return 0;
}
