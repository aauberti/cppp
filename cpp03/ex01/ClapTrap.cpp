#include "ClapTrap.hpp"

#define RESET "\e[0m"
#define	CYAN "\e[36m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

ClapTrap::ClapTrap(){
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << GREEN << "ClapTrap default constructor called\n" << RESET;
}

ClapTrap::ClapTrap(const std::string& name)
    : Name(name), Hit_points(10), Energy_points(10), Attack_damage(0) {
    std::cout << GREEN << "ClapTrap " << Name << " has been created.\n"<< RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : Name(other.Name), Hit_points(other.Hit_points), Energy_points(other.Energy_points), Attack_damage(other.Attack_damage) {
    std::cout << GREEN << "ClapTrap " << Name << " has been copied.\n"<< RESET;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        Name = other.Name;
        Hit_points = other.Hit_points;
        Energy_points = other.Energy_points;
        Attack_damage = other.Attack_damage;
    }
    std::cout << GREEN << "ClapTrap " << Name << " has been assigned.\n"<< RESET;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << GREEN << "ClapTrap " << Name << " has been destroyed.\n"<< RESET;
}

void ClapTrap::attack(const std::string& target) {
    if (Hit_points > 0 && Energy_points > 0) {
        std::cout << GREEN << Name << " attacks " << target << ", causing "
                  << Attack_damage << " points of damage!\n"<< RESET;
        Energy_points--;
    } else {
        std::cout << GREEN << Name << " cannot attack because it's out of HP or energy.\n"<< RESET;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount < 0 || amount > 2147483647) {
        std::cout << "Use a positve int for takeDamage\n";
        return ;
    }
    if (Hit_points > 0) {
        Hit_points -= amount;
        if (Hit_points < 0) Hit_points = 0;
        std::cout << Name << " takes " << amount << " points of damage! "
                  << "Remaining HP: " << Hit_points << "\n";
    } else {
        std::cout << Name << " has no HP left to take damage.\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (amount < 0 || amount > 2147483647) {
        std::cout << "Use a positve int for beRepaired\n";
        return ;
    }
    if (Hit_points > 0 && Energy_points > 0) {
        Hit_points += amount;
        Energy_points--;
        std::cout << Name << " repairs itself for " << amount << " points! "
                  << "New HP: " << Hit_points << "\n";
    } else {
        std::cout << Name << " cannot repair itself due to lack of HP or energy.\n";
    }
}


