
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {

    private:
        std::string ideas[100];

    public:
        Brain(void);
        Brain(const Brain& other);
        Brain& operator = (const Brain& other);
        ~Brain(void);

        std::string getIdeas(int index) const;
        void setIdeas(std::string idea, int index);

};

#endif
