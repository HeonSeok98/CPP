
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(const int rawBits) {
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = rawBits << fractionalBits;
}

Fixed::Fixed(const float rawBits) {
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = static_cast<int>(roundf(rawBits * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawBits = other.rawBits;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return rawBits >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
