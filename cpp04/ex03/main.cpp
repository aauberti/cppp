#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << "\n--- Additional tests ---" << std::endl;
    
    tmp = src->createMateria("unknown");
    if (tmp == NULL) {
        std::cout << "Creation of an unknown materia: OK (NULL)" << std::endl;
    }
    
    for (int i = 0; i < 5; i++) {
        tmp = src->createMateria("ice");
        me->equip(tmp);
        std::cout << "Equipment #" << i << " done" << std::endl;
    }
    
    me->use(10, *bob);
    std::cout << "Using an invalid slot: No effect expected" << std::endl;
    

    Character* original = new Character("original");
    original->equip(src->createMateria("ice"));
    original->equip(src->createMateria("cure"));

    Character* copy = new Character(*original);
    std::cout << "\nCharacter copy test:" << std::endl;
    std::cout << "Original uses materia 0: ";
    original->use(0, *bob);
    std::cout << "Copy uses materia 0: ";
    copy->use(0, *bob);

    original->unequip(0);
    std::cout << "Original after unequip: ";
    original->use(0, *bob);
    std::cout << "Copy after unequip of the original: ";
    copy->use(0, *bob);

    delete bob;
    delete me;
    delete src;
    delete original;
    delete copy;
    
    return 0;
}