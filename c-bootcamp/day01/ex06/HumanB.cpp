
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack(void) {
    std::cout << this->name << " attacks with his ";
    std::cout << this->weapon->name << "\n";
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

HumanB::HumanB(std::string n) {
	this->name = n;
	this->weapon = new Weapon();
}

HumanB::~HumanB(void) {}
