#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	
	ClapTrap	R2("R2D2");
	ScavTrap	Mario("Mario");

	R2.attack("C3");
	Mario.attack("C3");
	Mario.guardGate();
	R2.takeDamage(5);
	Mario.takeDamage(500);
	Mario.takeDamage(500);
	Mario.beRepaired(63);
	R2.beRepaired(2);
	Mario.takeDamage(30);
	R2.takeDamage(8);
	R2.takeDamage(1);
	Mario.guardGate();
	return 0;
}
