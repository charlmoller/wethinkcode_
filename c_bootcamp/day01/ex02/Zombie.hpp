#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

    public:

        std::string name;
        std::string type;

        Zombie(std::string, std::string); // name, type
        ~Zombie(void);
        void announce(void);

};

#endif // ZOMBIE_HPP
