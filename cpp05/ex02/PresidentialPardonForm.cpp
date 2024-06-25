
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.getTatget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.getTatget();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Creation Form", 25, 5), target(target) {}

const char* PresidentialPardonForm::NotSignedException::what(void) const throw() {
    return "Not signed...";
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {

    if (!this->getIsSigned()) {
        throw NotSignedException();
    }

    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}

std::string PresidentialPardonForm::getTatget() const {
    return this->target;
}

