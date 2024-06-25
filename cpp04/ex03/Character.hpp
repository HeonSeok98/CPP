
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {

    private:
        std::string name;
        AMateria* inventory[4];

    public:
        Character(void);
        Character(const Character& other);
        Character& operator = (const Character& other);
        virtual ~Character(void);

        Character(std::string const & name);

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

        AMateria* getInventory(int idx) const;
        void setInventory(int idx, AMateria* m);

};

#endif
