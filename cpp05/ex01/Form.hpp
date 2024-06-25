
#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        Form();

    public:
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        Form(const std::string& name, int gradeToSign, int gradeToExecute);

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

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif


