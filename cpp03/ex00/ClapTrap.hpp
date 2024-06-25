
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

    private:
        std::string name;
        unsigned int hitPoint;
        unsigned int energyPoint;
        unsigned int attackDamage;

    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator = (const ClapTrap& other);
        ~ClapTrap(void);
    
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
        std::string getName(void) const;
        unsigned int getHitPoint(void) const;
        unsigned int getEnergyPoint(void) const;
        unsigned int getAttackDamage(void) const;

        void setName(std::string name);
        void setHitPoint(unsigned int hitPoint);
        void setEnergyPoint(unsigned int energyPoint);
        void setAttackDamage(unsigned int attackDamage);

};

#endif
