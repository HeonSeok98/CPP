
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


# include "AForm.hpp"



class RobotomyRequestForm : public AForm {

    private:
        std::string target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string& target);

        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        void execute(Bureaucrat const& executor) const;

        std::string getTatget() const;

};

#endif
