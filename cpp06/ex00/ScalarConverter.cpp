
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    if (this != &other) {
        std::cout << "I can't do anything..." << std::endl;
    }
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
        std::cout << "I can't do anything..." << std::endl;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void printChar(double value) {

    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "char: impossible" << std::endl;
    }
    else {
        char c = static_cast<char>(value);
        if (32 <= c && c <= 126) {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
}

void printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void printFloat(double value) {
    if (static_cast<int>(value) == value) {
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    }
    else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void printDouble(double value) {
    if (static_cast<int>(value) == value) {
        std::cout << "double: " << value << ".0" << std::endl;
    }
    else {
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convert(std::string& input) {

    char* end;
    size_t len = input.length();
    char c = input[0];

    if (len == 1 && ((32 <= c && c <= 47) || (58 <= c && c <= 126))) {
        float value = c;
        // std::cout << "this is char"<< std::endl;
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
    else if (input.find('.') != std::string::npos || input.find("nan") != std::string::npos || input.find("inf") != std::string::npos || input[len - 1] == 'f') {
        if (len > 0 && input[len - 1] == 'f') {
            float value = std::atof(input.c_str());
            // std::cout << "this is float"<< std::endl;
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
        }
        else {
            double value = std::strtod(input.c_str(), &end);
            // std::cout << "this is double"<< std::endl;
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
        }
    }
    else {
        long long_value = std::strtol(input.c_str(), &end, 10);
        if (long_value < INT_MIN) {
            std::cout << "under flow!" << std::endl;
        }
        else if (long_value > INT_MAX) {
            std::cout << "over flow!" << std::endl;
        }
        else {
            int value = std::atoi(input.c_str());
            // std::cout << "this is int"<< std::endl;
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
        }
    }

}

