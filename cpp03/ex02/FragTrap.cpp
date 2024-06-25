
#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << this->getName() << " is created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << this->getName() << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    this->name = other.getName();
    this->hitPoint = other.getHitPoint();
    this->energyPoint = other.getEnergyPoint();
    this->attackDamage = other.getAttackDamage();
    std::cout << "FragTrap " << other.getName() << " is copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        this->name = other.getName();
        this->hitPoint = other.getHitPoint();
        this->energyPoint = other.getEnergyPoint();
        this->attackDamage = other.getAttackDamage();
        std::cout << "FragTrap " << other.getName() << " is assigned" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << this->getName() << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Highfive with " << this->getName() << "!" << std::endl;
}

