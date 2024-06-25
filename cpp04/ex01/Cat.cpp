
#include "Cat.hpp"

Cat::Cat(void) {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.getType();
    this->brain = new Brain(*other.getBrain());
    std::cout << "Cat copyed" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        this->type = other.getType();
        delete this->brain;
        this->brain = new Brain(*other.getBrain());
        std::cout << "Cat assigned" << std::endl;
    }
    return *this;
}

Cat::~Cat(void) {
    delete this->brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meeeeeeeeeeow" << std::endl;
}

Brain *Cat::getBrain() const {
    return this->brain;
}
