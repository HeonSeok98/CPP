
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.getTatget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.getTatget();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

const char* ShrubberyCreationForm::NotSignedException::what(void) const throw() {
	return "Not signed...";
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

    if (!this->getIsSigned()) {
        throw NotSignedException();
    }

    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\" << std::endl;

    ofs.close();
}

std::string ShrubberyCreationForm::getTatget() const {
    return this->target;
}

