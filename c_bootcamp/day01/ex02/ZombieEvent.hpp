#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <string>

class ZombieEvent {

    public:

        std::string type;

        void setZombieType(std::string); // type
        Zombie *newZombie(std::string name);
        Zombie *randomChump(void);

};

#endif // ZOMBIE_EVENT_HPP
