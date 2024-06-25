
#include "Floor.hpp"

Floor::Floor(void) {
    for (int i = 0; i < 4; i++) {
        this->materiaPool[i] = 0;
    }
}

Floor::Floor(const Floor& other) {
    for (int i = 0; i < 4; i++) {
        if (other.materiaPool[i]) {
            this->materiaPool[i] = other.materiaPool[i]->clone();
        }
        else {
            this->materiaPool[i] = 0;
        }
    }
}

Floor& Floor::operator = (const Floor& other) {
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

Floor::~Floor(void) {
    for (int i = 0; i < 4; i++) {
        if (materiaPool[i]) {
            delete materiaPool[i];
        }
    }
}


AMateria* Floor::pickup(int idx) {
    AMateria* tmp;
    if (0 <= idx && idx < 4) {
        if (this->materiaPool[idx]) {
            tmp = this->materiaPool[idx];
            this->materiaPool[idx] = 0;
            return tmp;
        }
    }
    return 0;
}

AMateria* Floor::getPool(int idx) const {
    if (0 <= idx && idx < 4) {
        return this->materiaPool[idx];
    }
    return 0;
}

void Floor::setPool(int idx, AMateria* m){
    if (0 <= idx && idx < 4) {
        if (this->materiaPool[idx]) {
            delete this->materiaPool[idx];
        }
        this->materiaPool[idx] = m;
    }
}

void putDown(Floor *floor, Character *character, int idx) {
    if (0 <= idx && idx < 4) {
        floor->setPool(idx, character->getInventory(idx));
    }
}
