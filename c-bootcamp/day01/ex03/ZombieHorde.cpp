
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

void ZombieHorde::announce(void) {
    for (int i = 0; i < this->N; ++i) {
        this->horde[i].announce();
    }
}

ZombieHorde::ZombieHorde(int N) {
    this->N = N;
    this->horde = new Zombie[N];
    for (int i = 0; i < this->N; ++i) {
        std::string name = "";
        for (int j = 0; j < 10; ++j)
            name.append(1, (char) ('a' + (rand() % 26)) );
        this->horde[i].name = name;
        this->horde[i].type = "HordeType";
    }
}

ZombieHorde::~ZombieHorde(void) {
    delete[] this->horde;
}
