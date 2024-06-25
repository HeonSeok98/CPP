
#include "Point.hpp"

// i * AB + j * AC = AP

// BX = B.getX() - A.getX()
// BY = B.getY() - A.getY()
// CX = C.getX() - A.getX()
// CY = C.getY() - A.getY()
// PX = P.getX() - A.getX()
// PY = p.getY() - A.getY()

// BX * i + CX * j = PX
// BY * i + CY * j = PY

// CX * BY * j  - CY * BX * j = PX * BY - PY * BX
// j = (PX * BY - PY * BX) / (CX * BY - CY * BX)
// i = (PX - (CX * j)) / BX

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    Fixed BX(b.getX() - a.getX());
    Fixed BY(b.getY() - a.getY());
    Fixed CX(c.getX() - a.getX());
    Fixed CY(c.getY() - a.getY());
    Fixed PX(point.getX() - a.getX());
    Fixed PY(point.getY() - a.getY());

    Fixed j((PX * BY - PY * BX) / (CX * BY - CY * BX));
    Fixed i((PX - (CX * j)) / BX);

    std::cout << i << std::endl;
    std::cout << j << std::endl;

    if (Fixed(0) >= i || Fixed(0) >= j || Fixed(1) <= i || Fixed(1) <= j || Fixed(1) <= i + j) {
        std::cout << "Point is not in triangle " << std::endl;
        return false;
    }

    std::cout << "Point is in triangle " << std::endl;
    return true;
}
