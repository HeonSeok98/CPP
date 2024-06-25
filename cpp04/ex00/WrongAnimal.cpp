
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    this->type = other.getType();
    std::cout << "WrongAnimal copyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
    if (this != &other) {
        this->type = other.getType();
        std::cout << "WrongAnimal assigned" << std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "This is wrong animal" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
