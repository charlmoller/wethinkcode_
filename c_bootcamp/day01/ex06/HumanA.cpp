
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack(void) {
    std::cout << this->name << " attacks with his ";
    std::cout << this->weapon->name << "\n";
}

HumanA::HumanA(std::string n, Weapon &w) {
	this->name = n;
	this->weapon = &w;
}

HumanA::~HumanA(void) {}
