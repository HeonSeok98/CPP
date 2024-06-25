
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    if (this != &other) {
        std::cout << "I can't do anything...." << std::endl;
    }
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        std::cout << "I can't do anything...." << std::endl;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string name, const std::string target) {

    std::string formArr[3];
    formArr[0] = "shrubbery request";
    formArr[1] = "robotomy request";
    formArr[2] = "presidential pardon request";

    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (formArr[i] == name) {
            index = i;
        }
    }

    switch (index) {
        case 0:
            return new ShrubberyCreationForm(target);
            __attribute__((fallthrough));
        case 1:
            return new RobotomyRequestForm(target);
            __attribute__((fallthrough));
        case 2:
            return new PresidentialPardonForm(target);
            __attribute__((fallthrough));
        default:
            throw DontExistException();
            break;
    }
}

const char* Intern::DontExistException::what(void) const throw() {
	return "Don't exist form...";
}
