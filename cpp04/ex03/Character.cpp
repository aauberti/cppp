#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character [" << name << "] created" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character [" << name << "] copied" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
        if (other.inventory[i] != NULL) {
            this->inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL) {
                this->inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character [" << name << "] destroyed" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
        }
    }
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }
        
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            std::cout << "Character [" << name << "] equipped with " << m->getType() << " materia in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Character [" << name << "] has no empty slot to equip materia" << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
        std::cout << "Character [" << name << "] unequipped materia from slot " << idx << std::endl;
        this->inventory[idx] = NULL;
    } else {
        std::cout << "Character [" << name << "] cannot unequip from invalid slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
        std::cout << "Character [" << name << "] uses materia from slot " << idx << " on " << target.getName() << std::endl;
        this->inventory[idx]->use(target);
    } else {
        std::cout << "Character [" << name << "] cannot use materia from invalid slot " << idx << std::endl;
    }
}