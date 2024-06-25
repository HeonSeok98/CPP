
# include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain created" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "no idea";
    }
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.getIdeas(i);
    }
    std::cout << "Brain copyed" << std::endl;
}

Brain& Brain::operator = (const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.getIdeas(i);
        }
        std::cout << "Brain assigned" << std::endl;
    }
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Brain destroyed" << std::endl;
}

std::string Brain::getIdeas(int index) const {
    if (index < 0 || index >= 100) {
        std::cerr << "Index out of range" << std::endl;
        return "";
    }
    else {
        return this->ideas[index];
    }
}

void Brain::setIdeas(std::string idea, int index) {
    if (index < 0 || index >= 100) {
        std::cerr << "Index out of range" << std::endl;
    }
    else {
        this->ideas[index] = idea;
    }
}
