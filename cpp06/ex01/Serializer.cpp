
#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    if (this != &other) {
        std::cout << "I can't do anything"<< std::endl;
    }
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
        std::cout << "I can't do anything"<< std::endl;
    }
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

