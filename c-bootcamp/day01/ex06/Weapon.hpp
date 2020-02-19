#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

    public:

        std::string name;

        Weapon(std::string name);
        Weapon(void);
        ~Weapon(void);
        void setType(std::string type);

};

#endif // WEAPON_HPP
