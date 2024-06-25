
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
    setName("_clap_name");
    this->name = "";
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {
    setName(name + "_clap_name");
    this->name = name;
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    this->name = other.name;
    this->hitPoint = other.getHitPoint();
    this->energyPoint = other.getEnergyPoint();
    this->attackDamage = other.getAttackDamage();
    std::cout << "DiamondTrap " << this->name << " is copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoint = other.getHitPoint();
        this->energyPoint = other.getEnergyPoint();
        this->attackDamage = other.getAttackDamage();
        std::cout << "DiamondTrap " << other.name << " is assigned" << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << this->name << " is destroyed" << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am DiamondTrap " << this->name << "!" << std::endl;
    std::cout << "My clap name is " << getName() << "!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
