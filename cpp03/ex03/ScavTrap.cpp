
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << this->getName() << " is created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << this->getName() << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    this->name = other.getName();
    this->hitPoint = other.getHitPoint();
    this->energyPoint = other.getEnergyPoint();
    this->attackDamage = other.getAttackDamage();
    std::cout << "ScavTrap " << other.getName() << " is copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        this->name = other.getName();
        this->hitPoint = other.getHitPoint();
        this->energyPoint = other.getEnergyPoint();
        this->attackDamage = other.getAttackDamage();
        std::cout << "ScavTrap " << other.getName() << " is assigned" << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoint <= 0) {
        std::cout << "ClapTrap " << this->name << " is unable.." << std::endl;
    }
    else if (this->energyPoint <= 0) {
        std::cout << "ClapTrap " << this->name << " has no energy point!" << std::endl;
    }
    else {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint--;
    }
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->getName() << " is gate keeper mode" << std::endl;
}
