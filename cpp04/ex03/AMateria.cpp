
#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {}

AMateria::AMateria(const AMateria& other) : type(other.getType()) {}

AMateria& AMateria::operator = (const AMateria& other) {
    if (this != &other) {
        // this->type = other.getType();
    }
    return *this;
}

AMateria::~AMateria(void) {}

AMateria::AMateria(std::string const& type) : type(type) {}

std::string const& AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* can not do anything to " << target.getName() << " *" << std::endl;
}
