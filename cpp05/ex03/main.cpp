
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {

    Intern someRandomIntern;
    AForm* rrf;

    try {
        rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
        std::cout << "create!" << std::endl;
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
