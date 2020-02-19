
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
    // Zombie
    Zombie test1 = Zombie("name1", "type1");
    Zombie test2 = Zombie("name2", "type2");
    test1.announce();
    test2.announce();

    // ZombieEvent
    ZombieEvent z_factory;
    z_factory.setZombieType("factory_type");
    Zombie *factory_zombie1 = z_factory.newZombie("FactoryZombie1WithName");
    Zombie *factory_zombie2 = z_factory.randomChump();
    Zombie *factory_zombie3 = z_factory.randomChump();
    Zombie *factory_zombie4 = z_factory.randomChump();
    Zombie *factory_zombie5 = z_factory.randomChump();
    Zombie *factory_zombie6 = z_factory.newZombie("FactoryZombie6WithName");
    factory_zombie1->announce();
    factory_zombie2->announce();
    factory_zombie3->announce();
    factory_zombie4->announce();
    factory_zombie5->announce();
    factory_zombie6->announce();

    delete factory_zombie1;
    delete factory_zombie2;
    delete factory_zombie3;
    delete factory_zombie4;
    delete factory_zombie5;
    delete factory_zombie6;
    return 0;
}
