
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/time.h>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string t) {
    this->type = t;
}

Zombie *ZombieEvent::newZombie(std::string name) {
	struct timeval ts; 
	gettimeofday(&ts, NULL);
	srand( ts.tv_usec );
    return new Zombie(name, this->type);
}

Zombie *ZombieEvent::randomChump(void) {
    std::string name = "";
    std::string names[55] = {
		"jen", "sen", "gus", "tavo",
		"cros", "by", "kris", "topher",
		"har", "old", "and", "ers",
		"bod", "ie", "ste", "fan",
		"bo", "den", "tyr", "ell",
		"jen", "son", "and", "er",
		"os", "man", "ra", "fe",
		"han", "sel", "hag", "an",
		"kris", "tofer", "iv", "er",
		"ein", "er", "jan", "sen",
		"han", "ler", "way", "de",
		"han", "sen", "jan", "son"
    };
    name.append(names[ ((rand() % 23) * 2) + 0 ] );
    name.append(names[ ((rand() % 23) * 2) + 1 ] );
    name[0] = toupper(name[0]);
    return new Zombie(name, this->type);
}