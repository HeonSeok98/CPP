
#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    this->type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->type = other.getType();
    std::cout << "WrongCat copyed" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
    if (this != &other) {
        this->type = other.getType();
        std::cout << "WrongCat assigned" << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "This is wrong cat" << std::endl;
}
