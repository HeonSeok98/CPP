
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j;
    delete i;

    Animal *meta[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5) {
            meta[i] = new Dog();
        }
        else {
            meta[i] = new Cat();
        }
    }

    for (int i = 0; i < 10; i++) {
        delete meta[i];
    }

    std::cout << std::endl;

    const Dog *dog = new Dog();
    const Dog *dog2 = new Dog(*dog);

    std::cout << std::endl;

    std::cout << dog->getBrain()->getIdeas(0) << std::endl;
    dog->getBrain()->setIdeas("I want to eat!",0);
    std::cout << dog->getBrain()->getIdeas(0) << std::endl;
    std::cout << dog2->getBrain()->getIdeas(0) << std::endl;

    std::cout << std::endl;

    delete dog;
    delete dog2;

    return 0;
}
