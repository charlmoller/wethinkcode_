
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    // Zombie
    Zombie test1 = Zombie("name1", "type1");
    Zombie test2 = Zombie("name2", "type2");
    test1.announce();
    test2.announce();

    ZombieHorde *zombie_horde = new ZombieHorde(10);
    zombie_horde->announce();

    delete zombie_horde;
    return 0;
}
