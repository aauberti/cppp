#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main() {
    ClapTrap clappy("Clappy");
    ScavTrap clapclap("ClapClap");
    FragTrap clip("Clip");
    clappy.attack("target1");
    clappy.takeDamage(5);
	clappy.takeDamage(4);
    clappy.beRepaired(3);
    clapclap.takeDamage(5);
    clapclap.attack("target2");
    clapclap.takeDamage(4);
    clapclap.beRepaired(3);
    clapclap.guardGate();
    clip.attack("target3");
    clip.takeDamage(-2);
    clip.beRepaired(3);
    clip.highFivesGuys();

    return 0;
}
