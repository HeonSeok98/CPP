
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name(""), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    this->name = other.getName();
    this->hitPoint = other.getHitPoint();
    this->energyPoint = other.getEnergyPoint();
    this->attackDamage = other.getAttackDamage();
    std::cout << "ClapTrap " << this->name << " is copied" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
    if (this != &other) {
        this->name = other.getName();
        this->hitPoint = other.getHitPoint();
        this->energyPoint = other.getEnergyPoint();
        this->attackDamage = other.getAttackDamage();
        std::cout << "ClapTrap " << other.getName() << " is assigned" << std::endl;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoint <= 0) {
        std::cout << "ClapTrap " << this->name << " is unable.." << std::endl;
    }
    else if (this->energyPoint <= 0) {
        std::cout << "ClapTrap " << this->name << " has no energy point!" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoint == 0) {
        std::cout << "ClapTrap " << this->name << " is unable.." << std::endl;
    }
    else if (this->energyPoint == 0) {
        std::cout << "ClapTrap " << this->name << " has no energy point!" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->name << " take " << amount << " damage!" << std::endl;
        if (this->hitPoint < amount) {
            this->hitPoint = 0;
        }
        else {
            this->hitPoint -= amount;
        }
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoint == 0) {
        std::cout << "ClapTrap " << this->name << " is unable.." << std::endl;
    }
    else if (this->energyPoint == 0) {
        std::cout << "ClapTrap " << this->name << " has no energy point!" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->name << " is repaired " << amount << " point!" << std::endl;
        this->energyPoint--;
        this->hitPoint += amount;
    }
}
    
std::string ClapTrap::getName(void) const {
    return this->name;
}

unsigned int ClapTrap::getHitPoint(void) const {
    return this->hitPoint;
}

unsigned int ClapTrap::getEnergyPoint(void) const {
    return this->energyPoint;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return this->attackDamage;
}

void ClapTrap::setName(std::string name) {
    this->name = name;
}

void ClapTrap::setHitPoint(unsigned int hitPoint) {
    this->hitPoint = hitPoint;
}

void ClapTrap::setEnergyPoint(unsigned int energyPoint) {
    this->energyPoint = energyPoint;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}
