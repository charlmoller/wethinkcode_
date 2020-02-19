
#include <iostream>
#include "Pony.hpp"

void Pony::neigh(void) {
    std::cout << "This pony, named " << name;
    std::cout << ", can go " << top_speed << " km/h.\n";
}

Pony::Pony(std::string n, int s) : name(n), top_speed(s) {}

Pony::~Pony(void) {}