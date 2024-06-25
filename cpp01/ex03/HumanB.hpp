
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

    private:
        std::string name;
        Weapon *weapon;

    public:
        void attack() const ;
        HumanB(std::string name);
        void setWeapon(Weapon *weapon);


};

#endif
