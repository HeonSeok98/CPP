#include "Bureaucrat.hpp"

int main() {

    Bureaucrat heolee("heolee", 42);
    Bureaucrat dna("dna", 15);
    Form form("important", 30, 30);


    heolee.signForm(form);
    std::cout << form << std::endl;
    dna.signForm(form);
    std::cout << form << std::endl;

    return 0;
}
