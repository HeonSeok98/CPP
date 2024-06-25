
#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *horde = new Zombie[N];
    std::stringstream ss;

    for (int i = 0; i < N; i++) {
        ss.str("");
        ss << i + 1;
        horde[i].setName(name + ss.str());
    }
    return horde;
}

