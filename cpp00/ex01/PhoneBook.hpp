
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        int contactNum;
        Contact contacts[8];
        std::string cutStr(std::string str);
    public:
        PhoneBook();
        void add(int index);
        void search(void);
};

#endif
