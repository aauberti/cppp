#include "FragTrap.hpp"

#define RESET "\e[0m"
#define	CYAN "\e[36m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

FragTrap::FragTrap() : ClapTrap() {
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << YELLOW << "FragTrap default constructor called\n" << RESET;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << YELLOW << "FragTrap " << name << " has spawn.\n" << RESET;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << YELLOW << "FragTrap copy constructor called\n" << RESET;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << YELLOW << "FragTrap assignment operator called\n" << RESET;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << YELLOW << "FragTrap " << Name << " cleaned\n" << RESET;
}

void FragTrap::highFivesGuys() {
    std::cout << YELLOW << "FragTrap " << Name << "want a high five \n" << RESET;
}