
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {

    protected:
        std::string const type;

    public:
        AMateria(void);
        AMateria(const AMateria& other);
        AMateria& operator = (const AMateria& other);
        virtual ~AMateria(void);

        AMateria(std::string const & type);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

};

#endif
