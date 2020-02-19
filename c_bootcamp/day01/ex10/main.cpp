
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

void handleBlank(void) {
    std::string line;
    while (!std::cin.eof()) {
        std::getline(std::cin, line);
        if (!std::cin.eof())
            std::cout << line << "\n";
    }
}

void handleFile(const char *file) {
    std::ifstream ifile ( file );
    if (ifile.is_open()) {
        for (std::string line; std::getline(ifile, line);)
            std::cout << line << "\n";
        if (((std::ifstream::badbit & ifile.rdstate()) != 0))
            std::cout << "cato9tails: " << file << ": Is a directory\n";
    } else std::cout << "cato9tails: " << file << ": No such file or directory\n";
}

int main(int argc, char const *argv[])
{
    if (argc == 1) {
        handleBlank();
    } else {
        for (int i = 1; i < argc; ++i)
        {
            if (std::string(argv[i]) == "-") {
                handleBlank();
            } else {
                handleFile(argv[i]);
            }
        }
    }
    return 0;
}
