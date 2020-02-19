#ifndef ZOMBIE_HORDE_HPP
#define ZOMBIE_HORDE_HPP

#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

class ZombieHorde {

    public:

        int N;
        Zombie *horde;

        ZombieHorde(int N);
        ~ZombieHorde(void);
        void announce(void);

};

#endif // ZOMBIE_HORDE_HPP
