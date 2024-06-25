
#include "ClapTrap.hpp"

int main() {

    ClapTrap heolee("heolee");
    ClapTrap dna("dna");

    heolee.attack("dna");
    dna.takeDamage(10);
    dna.attack("heolee");

    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);
    heolee.beRepaired(1);

    return 0;
}
