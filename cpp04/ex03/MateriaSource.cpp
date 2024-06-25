
# include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        this->materiaPool[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.materiaPool[i]) {
            this->materiaPool[i] = other.materiaPool[i]->clone();
        }
        else {
            this->materiaPool[i] = 0;
        }
    }
}

MateriaSource& MateriaSource::operator = (const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (materiaPool[i]) {
                delete materiaPool[i];
            }
            if (other.materiaPool[i]) {
                this->materiaPool[i] = other.materiaPool[i]->clone();
            }
            else {
                this->materiaPool[i] = 0;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        if (materiaPool[i]) {
            delete materiaPool[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!this->materiaPool[i]) {
            this->materiaPool[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++) {
        if (this->materiaPool[i]) {
            if (this->materiaPool[i]->getType() == type) {
                return this->materiaPool[i]->clone();
            }
        }
    }
    return 0;
}

