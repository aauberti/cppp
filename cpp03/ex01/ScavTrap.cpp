#include "ScavTrap.hpp"

#define RESET "\e[0m"
#define	CYAN "\e[36m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

ScavTrap::ScavTrap() : ClapTrap() {
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << CYAN << "ScavTrap default constructor called\n" << RESET;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << CYAN << "ScavTrap " << name << " has been edited.\n" << RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << CYAN << "ScavTrap copy constructor called\n" << RESET;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << CYAN << "ScavTrap assignment operator called\n" << RESET;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << CYAN << "ScavTrap " << Name << " destructor called\n" << RESET;
}

void ScavTrap::attack(const std::string& target) {
    if (Hit_points > 0 && Energy_points > 0) {
        std::cout << CYAN << "ScavTrap " << Name << " attacks " << target << " with a mighty attack, causing "
                  << Attack_damage << " points of damage!\n" << RESET;
        Energy_points--;
    } else {
        std::cout << CYAN << "ScavTrap " << Name << " cannot attack because it's out of HP or energy.\n" << RESET;
    }
}

void ScavTrap::guardGate() {
    std::cout << CYAN << "ScavTrap is now in Gate keeper mode\n" << RESET;
}