
#include "Serializer.hpp"

int main() {

    Data p;
    p.x = 0;
    p.y = 0;
    p.z = 0;

    if (&p == Serializer::deserialize(Serializer::serialize(&p))) {
        std::cout << "pointer is same"<< std::endl;
    }

    return 0;
}
