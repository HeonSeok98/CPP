
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
    contactNum = 0;
}

void PhoneBook::add(int index) {
    std::string input;

    std::cout << "first name : ";
    std::getline(std::cin, input);
    if (std::cin.eof() || input == "") {
        std::cout << "empty input!" << std::endl;
        return;
    }
    this->contacts[index].setFirstName(input);

    std::cout << "last name : ";
    std::getline(std::cin, input);
    if (std::cin.eof() || input == "") {
        std::cout << "empty input!" << std::endl;
        return;
    }
    this->contacts[index].setLastName(input);

    std::cout << "nickname : ";
    std::getline(std::cin, input);
    if (std::cin.eof() || input == "") {
        std::cout << "empty input!" << std::endl;
        return;
    }
    this->contacts[index].setNickname(input);

    std::cout << "phone number : ";
    std::getline(std::cin, input);
    if (std::cin.eof() || input == "") {
        std::cout << "empty input!" << std::endl;
        return;
    }
    this->contacts[index].setPhoneNumber(input);

    std::cout << "darkest secret : ";
    std::getline(std::cin, input);
    if (std::cin.eof() || input == "") {
        std::cout << "empty input!" << std::endl;
        return;
    }
    this->contacts[index].setDarkestSecret(input);

    if (this->contactNum < 8)
        this->contactNum += 1;
}

std::string PhoneBook::cutStr(std::string str) {
    if (str.size() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::search() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|" ;
    std::cout << std::setw(10) << "first name" << "|" ;
    std::cout << std::setw(10) << "last name" << "|" ;
    std::cout << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    int i = 0;
    while (i < this->contactNum)
    {
        std::cout << "|" << std::setw(10) << i << "|" ;
        std::cout << std::setw(10) << PhoneBook::cutStr(this->contacts[i].getFirstName()) << "|" ;
        std::cout << std::setw(10) << PhoneBook::cutStr(this->contacts[i].getLastName()) << "|" ;
        std::cout << std::setw(10) << PhoneBook::cutStr(this->contacts[i].getNickname()) << "|" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        i++;
    }

    std::string input;
    int index;
    std::cout << "Index : ";
    std::getline(std::cin, input);
    if (std::cin.eof() || input == "") {
        std::cout << "empty input!" << std::endl;
        return;
    }
    index = input[0] - '0';
    if (std::cin.fail() || input.size() != 1 || index < 0 || this->contactNum - 1 < index) {
        std::cout << "wrong input!" << std::endl;
	}
    else {
        std::cout << "first name : "<< this->contacts[index].getFirstName() << std::endl;
        std::cout << "last name : "<< this->contacts[index].getLastName() << std::endl;
        std::cout << "nickname : "<< this->contacts[index].getNickname() << std::endl;
        std::cout << "phone number : "<< this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "darkest secret : "<< this->contacts[index].getDarkestSecret() << std::endl;
    }
}
