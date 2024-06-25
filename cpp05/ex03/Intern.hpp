
#ifndef INTERN_HPP
# define INTERN_HPP

# include <stdexcept>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern {

    public:

        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string name, const std::string target);

        class DontExistException : public std::exception {
            public:
                const char* what() const throw();
        };

};

#endif


