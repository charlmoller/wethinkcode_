
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#define FIELDS 11

class Contact {

public:
    
    std::string av[FIELDS];

    void search(int i) {
        std::cout << "|" << std::setw(10) << i << "|";
        for (int j = 0; j < 3; ++j) {
            int lg = (this->av[j].size() > 10);
            std::cout << std::setw(10 - lg);
            std::cout << (lg ? this->av[j].substr(0, 9) : this->av[j]);
            std::cout << (lg ? ".|" : "|");
        }
        std::cout << "\n";
    }

    void add(int curr, std::string val) {
        this->av[curr] = val;
    }

};

int main(void) {
    
    std::string fields[FIELDS] = {
        "First name",
        "Last name",
        "Nick name",
        "Login",
        "Postal address",
        "Email address",
        "Phone number",
        "Birthday date",
        "Favorite meal",
        "Underwear color",
        "Darkest secret"
    }; 
    Contact contacts[8];
    int curr = 0;
    std::string line;

    while (line != "EXIT" && !std::cin.eof()) {

        std::cout << "$ ";
        std::getline(std::cin, line);

        if (line == "ADD") {
            
            if (curr != 8) {
                for (int i = 0; i < FIELDS; i++)
                {
                    std::cout << std::setw(16) << fields[i] << " : ";
                    std::getline(std::cin, line);
                    contacts[curr].add(i, line);
                }
                curr++;
            } else std::cout << "Phone Book is full\n";
        
        } else if (line == "SEARCH") {
            for (int i = 0; i < curr; i++){
                contacts[i].search(i);
            }
            std::cout << std::setw(16) << "Contact index : ";
            std::getline(std::cin, line);
            std::istringstream istream(line);
            int search;
            if (istream >> search && search < curr) {
                for (int i = 0; i < FIELDS; i++) {
                    std::cout << std::setw(16) << fields[i] << " : ";
                    std::cout << contacts[search].av[i] << "\n";
                }
            } else std::cout << "Invalid input\n";
        }
    }
    std::cout << "\nCheers\n";
}
