
#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.getTatget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.getTatget();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Creation Form", 72, 45), target(target) {}

const char* RobotomyRequestForm::NotSignedException::what(void) const throw() {
	return "Not signed...";
}

bool fiftyPercentChance() {
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    return t->tm_sec == 1;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {

    if (!this->getIsSigned()) {
        throw NotSignedException();
    }

    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    if (fiftyPercentChance()) {
        std::cout << "Drillllllll.... " << this->target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Failure!" << std::endl;
    }

}

std::string RobotomyRequestForm::getTatget() const {
    return this->target;
}
