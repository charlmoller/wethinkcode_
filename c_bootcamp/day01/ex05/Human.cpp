
#include <iostream>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include "Human.hpp"
#include "Brain.hpp"

std::string Human::identify(void) {
    return this->getBrain().identify();
}

Brain Human::getBrain(void) {
    return this->brain;
}

Human::Human() {}

Human::~Human(void) {}