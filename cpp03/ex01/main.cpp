#include "ScavTrap.hpp"

int main() {

    ScavTrap heolee("heolee");
    ClapTrap dna("dna");

    heolee.attack("dna");
    dna.attack("heolee");
    heolee.guardGate();

    return 0;
}