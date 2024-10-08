
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Floor.hpp"


int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    Floor* floor = new Floor();

    putDown(floor, (Character *)me, 0);
    putDown(floor, (Character *)me, 1);
    putDown(floor, (Character *)me, 2);
    putDown(floor, (Character *)me, 3);

    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);

    delete floor;
    delete bob;
    delete me;
    delete src;
    return 0;
}

