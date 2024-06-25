
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {

    Point A(0, 0);
    Point B(3, 0);
    Point C(0, 3);
    Point P(1.5f, 1.4f);

    bsp(A, B, C, P);

    return 0;
}
