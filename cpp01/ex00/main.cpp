
#include "Zombie.hpp"

int	main() {

    randomChump("stackZombie");
    Zombie *heapZombie = newZombie("heapZombie");

    heapZombie->announce();
    delete heapZombie;
    
    return 0;
}
