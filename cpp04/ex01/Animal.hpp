
#ifndef ANIMAl_HPP
# define ANIMAl_HPP

# include <iostream>

class Animal {

    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal& other);
        Animal& operator = (const Animal& other);
        virtual ~Animal(void);

        virtual void makeSound() const;
        std::string getType() const;

};

#endif
