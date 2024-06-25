
#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;
    std::string level = argv[1];

    if (argc != 2) {
        std::cout << "Bad input!" << std::endl;
        return 1;
    }
    if (level == "DEBUG" ||level == "INFO" || level == "WARNING" || level == "ERROR") {
        harl.complain(level);
    }
    else {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

    return 0;
}

