
#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other) {
    this->type = other.getType();
    std::cout << "Animal copyed" << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other) {
        this->type = other.getType();
        std::cout << "Animal assigned" << std::endl;
    }
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
