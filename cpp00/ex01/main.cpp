
#include <iostream>
#include "PhoneBook.hpp"

int	main() {
    std::string command;
    PhoneBook phonebook;
    int index;

    index = 0;
    while (true) {
        std::cout << "you can use ADD, SEARCH, EXIT : ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "ADD") {
            phonebook.add(index);
            index += 1;
            index %= 8;
        }
        else if (command == "SEARCH") {
            phonebook.search();
        }
        else if (command == "EXIT") {
            std::cout << "get out of phonebook" << std::endl;
            break ;
        }
        else {
            std::cout << command << " is wrong command!" << std::endl;
        }
        if (std::cin.eof())
            break;
    }
    return 0;
}
