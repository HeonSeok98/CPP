
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

    try {
        Bureaucrat heolee1("heolee1", 49);
        ShrubberyCreationForm pretty("pretty");

        heolee1.signForm(pretty);

        heolee1.executeForm(pretty);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat heolee2("heolee2", 40);
        RobotomyRequestForm robo("robo");

        heolee2.signForm(robo);

        heolee2.executeForm(robo);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat heolee3("heolee3", 30);
        PresidentialPardonForm president("president");

        heolee3.signForm(president);

        heolee3.executeForm(president);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
