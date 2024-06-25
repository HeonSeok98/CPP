
#include "Cat.hpp"

Cat::Cat(void) {
    this->type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.getType();
    std::cout << "Cat copyed" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other) {
        this->type = other.getType();
        std::cout << "Cat assigned" << std::endl;
    }
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meeeeeeeeeeow" << std::endl;
}
