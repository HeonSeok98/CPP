
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

    private:
        int rawBits;
        static const int fractionalBits = 8;

    public:
        Fixed(void);
        Fixed(const int rawBits);
        Fixed(const float rawBits);
        Fixed(const Fixed &fixed);
        Fixed& operator = (const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
