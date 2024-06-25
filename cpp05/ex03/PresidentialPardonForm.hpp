
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


# include "AForm.hpp"



class PresidentialPardonForm : public AForm {

    private:
        std::string target;
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string& target);

        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        void execute(Bureaucrat const& executor) const;

        std::string getTatget() const;

};

#endif
