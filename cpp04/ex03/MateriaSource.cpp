#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource created" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copied" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
        if (other.templates[i] != NULL) {
            this->templates[i] = other.templates[i]->clone();
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {

        for (int i = 0; i < 4; i++) {
            if (this->templates[i] != NULL) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (other.templates[i] != NULL) {
                this->templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destroyed" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL) {
            delete this->templates[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }
        
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] == NULL) {
            this->templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << " materia" << std::endl;
            return;
        }
    }
    
    std::cout << "MateriaSource is full, cannot learn more materias" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type) {
            std::cout << "MateriaSource creates new " << type << " materia" << std::endl;
            return this->templates[i]->clone();
        }
    }
    std::cout << "MateriaSource doesn't know " << type << " materia" << std::endl;
    return NULL;
}
