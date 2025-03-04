#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main() {
    ClapTrap clappy("Clappy");
    ScavTrap clapclap("ClapClap");

    clappy.attack("target1");
    clappy.takeDamage(5);
	clappy.takeDamage(4);
    clappy.beRepaired(3);
    clapclap.takeDamage(5);
    clapclap.attack("GoodGood");
    clapclap.takeDamage(4);
    clapclap.beRepaired(3);
    clappy.attack("target2"); 

    return 0;
}
