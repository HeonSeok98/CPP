
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer {

    private:
        Serializer();
        Serializer(const Serializer& other);

    public:
        Serializer& operator=(const Serializer& other);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);

        static Data* deserialize(uintptr_t raw);

};

#endif
