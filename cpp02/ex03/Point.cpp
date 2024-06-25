
#include "Point.hpp"

Point::Point(void) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

Point& Point::operator = (const Point &other) {
    if (this != &other) {
        std::cout << "Const can't change..." << std::endl;
    }
    return *this;
}

Point::~Point(void) {}

Fixed Point::getX(void) const {
    return this->x;
}

Fixed Point::getY(void) const {
    return this->y;
}
