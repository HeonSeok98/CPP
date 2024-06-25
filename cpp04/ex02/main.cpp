
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j;
    delete i;

    // const Animal* meta = new Animal();
    // delete meta;

    return 0;
}
