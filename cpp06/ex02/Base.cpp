
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

// Base::Base() {}

Base::~Base() {}

Base* generate(void) {
    std::time_t timer;
    std::tm* time;
    timer = std::time(NULL);
    time = std::localtime(&timer);

    if (time->tm_sec % 3 == 0) {
        return new A;
    }
    else if (time->tm_sec % 3 == 1) {
        return new B;
    }
    else {
        return new C;
    }
}

void identify(Base* p) {
    std::cout << "this is pointer" << std::endl;
    if (dynamic_cast<A*>(p)) {
        std::cout << "this is A" << std::endl;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "this is B" << std::endl;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "this is C" << std::endl;
    }
}

void identify(Base& p) {
    std::cout << "this is reference" << std::endl;

    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "this is A" << std::endl;
    } catch (std::exception&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "this is B" << std::endl;
    } catch (std::exception&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "this is C" << std::endl;
    } catch (std::exception&) {}

}
