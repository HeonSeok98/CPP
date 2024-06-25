
#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEGUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {

    void (Harl::*f)(void);

    switch (level[0]) {
        case 'D':
            f = &Harl::debug;
            (this->*f)();
            __attribute__((fallthrough));
        
        case 'I':
            f = &Harl::info;
            (this->*f)();
            __attribute__((fallthrough));
        
        case 'W':
            f = &Harl::warning;
            (this->*f)();
            __attribute__((fallthrough));
            
        case 'E':
            f = &Harl::error;
            (this->*f)();
            break ;
    }

}

