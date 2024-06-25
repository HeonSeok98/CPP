
#ifndef WRONGANIMAl_HPP
# define WRONGANIMAl_HPP

# include <iostream>

class WrongAnimal {

    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator = (const WrongAnimal& other);
        virtual ~WrongAnimal(void);

        void makeSound() const;
        std::string getType() const;

};

#endif
