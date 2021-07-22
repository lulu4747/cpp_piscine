#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	
	ClapTrap	R2("R2D2");
	ScavTrap	Mario("Mario");
	FragTrap	Archi("Samus");

	R2.attack("C3");
	Mario.attack("C3");
	Archi.attack("C3");
	Mario.guardGate();
	Archi.highFivesGuys();
	R2.takeDamage(5);
	Archi.takeDamage(85);
	Archi.takeDamage(85);
	Archi.beRepaired(3);
	R2.takeDamage(1);
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
