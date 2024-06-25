

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Floor {

    private:
        AMateria* materiaPool[4];

    public:
        Floor(void);
        Floor(const Floor& other);
        Floor& operator = (const Floor& other);
        ~Floor(void);

        AMateria* pickup(int idx);
        AMateria* getPool(int idx) const;
        void setPool(int idx, AMateria* m);

};


void putDown(Floor *floor, Character *character, int inx);

#endif
