
#include <iostream>
#include <stdio.h>
#include <string>
#include "Zombie.hpp"

void Zombie::announce(void) {
    printf("<%s (%s)> Braiiiiiiinnnssss\n",
        this->name.c_str(),
        this->type.c_str()
    );
}

Zombie::Zombie() {}

Zombie::Zombie(std::string n, std::string t) : name(n), type(t) {}

Zombie::~Zombie(void) {}