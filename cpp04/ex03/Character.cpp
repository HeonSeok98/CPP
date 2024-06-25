
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : name("") {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = 0;
    }
}

Character::Character(const Character& other) : name(other.getName()) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            this->inventory[i] = other.inventory[i]->clone();
        }
        else {
            this->inventory[i] = 0;
        }
    }
}

Character& Character::operator = (const Character& other) {
    if (this != &other) {
        this->name = other.getName();
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
            }
            if (other.inventory[i]) {
                this->inventory[i] = other.inventory[i]->clone();
            }
            else {
                this->inventory[i] = 0;
            }
        }
    }
    return *this;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = 0;
    }
}

std::string const& Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (0 <= idx && idx < 4) {
        this->inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (0 <= idx && idx < 4) {
        this->inventory[idx]->use(target);
    }
}

AMateria* Character::getInventory(int idx) const {
    if (0 <= idx && idx < 4) {
        return this->inventory[idx];
    }
    return 0;
}

void Character::setInventory(int idx, AMateria* m){
    if (0 <= idx && idx < 4) {
        if (this->inventory[idx]) {
            delete this->inventory[idx];
        }
        this->inventory[idx] = m;
    }
}
