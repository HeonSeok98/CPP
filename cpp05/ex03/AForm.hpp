
#ifndef AFORM_HPP
# define AFORM_HPP

# include <stdexcept>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        AForm();

    public:
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        AForm(const std::string& name, int gradeToSign, int gradeToExecute);

        void beSigned(Bureaucrat& bureaucrat);

        const std::string& getName() const ;
        bool getIsSigned() const ;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif


