
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Weapon.hpp"

void Weapon::setType(std::string type) {
    this->name = type;
}

Weapon::Weapon(std::string n) : name(n) {}

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}
