
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {

    if (argc != 4) {
        std::cerr << "Bad argument!" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (filename == "" || s1 == "") {
        std::cerr << "Bad argument!" << std::endl;
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Can not open file!" << std::endl;
        return 1;
    }

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Can not make replace file!" << std::endl;
        return 1; 
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}


