
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Brain.hpp"

std::string Brain::identify(void) {
    return this->address;
}

Brain::Brain() {
    std::stringstream buffer;
    buffer << this;
    this->address = buffer.str();
}

Brain::~Brain(void) {}
