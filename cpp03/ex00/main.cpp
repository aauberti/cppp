#include "ClapTrap.hpp"

int main() {
    ClapTrap clappy("Clappy");

    ClapTrap goodgood("Goodgood");

    clappy.attack("target1");
    clappy.takeDamage(0);
	clappy.takeDamage(4);
    clappy.beRepaired(3);
    goodgood.takeDamage(11);
    goodgood.beRepaired(10);

    clappy.attack("target2"); 

    return 0;
}
