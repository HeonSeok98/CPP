
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP


# include "AForm.hpp"



class ShrubberyCreationForm : public AForm {

    private:
        std::string target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string& target);

        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        void execute(Bureaucrat const& executor) const;

        std::string getTatget() const;



};

#endif
