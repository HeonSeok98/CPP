
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
    this->rawBits = 0;
}

Fixed::Fixed(const int rawBits) {
    this->rawBits = rawBits<< fractionalBits;
}

Fixed::Fixed(const float rawBits) {
    this->rawBits = static_cast<int>(roundf(rawBits * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->rawBits = other.rawBits;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
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

bool Fixed::operator>(const Fixed& other) const {
    if (this->toFloat() > other.toFloat()) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator<(const Fixed& other) const {
    if (this->toFloat() < other.toFloat()) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator>=(const Fixed& other) const {
    if (this->toFloat() >= other.toFloat()) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator<=(const Fixed& other) const {
    if (this->toFloat() <= other.toFloat()) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator==(const Fixed& other) const {
    if (this->toFloat() == other.toFloat()) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator!=(const Fixed& other) const {
    if (this->toFloat() !=other.toFloat()) {
        return true;
    }
    else {
        return false;
    }
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed((this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() == 0) {
        std::cout << "divide by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->rawBits++;
    return *this;
}

const Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->rawBits++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->rawBits--;
    return *this;
}

const Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->rawBits--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a < b) {
        return b;
    }
    else {
        return a;
    }
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a < b) {
        return b;
    }
    else {
        return a;
    }
}
