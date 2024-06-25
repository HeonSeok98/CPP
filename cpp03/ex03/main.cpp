
#include "DiamondTrap.hpp"

int main() {

    DiamondTrap heolee("heolee");
    DiamondTrap heolee2(heolee);
    ClapTrap dna("dna");

    heolee.whoAmI();
    heolee.attack("dna");

    return 0;
}
