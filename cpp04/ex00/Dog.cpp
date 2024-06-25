
#include "Dog.hpp"

Dog::Dog(void) {
    this->type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->type = other.getType();
    std::cout << "Dog copyed" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        this->type = other.getType();
        std::cout << "Dog assigned" << std::endl;
    }
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wooooooooooof" << std::endl;
}
