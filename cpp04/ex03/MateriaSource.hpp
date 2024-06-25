

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

    private:
        AMateria* materiaPool[4];

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator = (const MateriaSource& other);
        virtual ~MateriaSource(void);

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const& type);

};

#endif
