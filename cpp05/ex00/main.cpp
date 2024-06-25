
#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat heolee("heolee1", 42);
        std::cout << heolee << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;

    try {
        Bureaucrat heolee("heolee2", 0);
        std::cout << heolee << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;

    try {
        Bureaucrat heolee("heolee3", 200);
        std::cout << heolee << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;

    try {
        Bureaucrat heolee("heolee4", 1);
        std::cout << heolee << std::endl;
        heolee.incrementGrade();
        std::cout << heolee << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;

    try {
        Bureaucrat heolee("heolee5", 150);
        std::cout << heolee << std::endl;
        heolee.decrementGrade();
        std::cout << heolee << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

