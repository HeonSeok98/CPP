
#include "Dog.hpp"

Dog::Dog(void) {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->type = other.getType();
    this->brain = new Brain(*other.getBrain());
    std::cout << "Dog copyed" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other) {
        this->type = other.getType();
        delete this->brain;
        this->brain = new Brain(*other.getBrain());
        std::cout << "Dog assigned" << std::endl;
    }
    return *this;
}

Dog::~Dog(void) {
    delete this->brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wooooooooooof" << std::endl;
}

Brain *Dog::getBrain() const {
    return this->brain;
}
