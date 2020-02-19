
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int const INIT_HEALTH = 100;
int const INIT_HEALTH_MAX = 100;
int const INIT_ENERGY = 100;
int const INIT_ENERGY_MAX = 100;
int const INIT_LEVEL = 1;
int const INIT_MELEE_DAMAGE = 30;
int const INIT_RANGE_DAMAGE = 20;
int const INIT_ARMOR = 5;

void ScavTrap::challengeNewcomer(std::string const & target) {
	std::string challenge[] = {
		"to a duel",
		"to a battle",
		"to a stare off",
		"to a thumb war",
		"sword fight"
	};
	std::cout << getName() << " challenges " << target << " " << challenge[rand() % 5] << "\n";
}

ScavTrap::ScavTrap( std::string const & s ) : ClapTrap(s) {
	std::cout << "Constructed ScavTrap " << s << "\n";
	std::cout << "Roar Roar!! " << "\n";
	setHealth(INIT_HEALTH);
	setHealthMax(INIT_HEALTH_MAX);
	setEnergy(INIT_ENERGY);
	setEnergyMax(INIT_ENERGY_MAX);
	setLevel(INIT_LEVEL);
	setMeleeDamage(INIT_MELEE_DAMAGE);
	setRangedDamage(INIT_RANGE_DAMAGE);
	setArmor(INIT_ARMOR);
}

ScavTrap::ScavTrap( const ScavTrap &cc ) : ClapTrap(cc) {
	std::cout << "Constructed ScavTrap\n";
	std::cout << "Roar Roar!! " << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ass) {
	ClapTrap::operator=(ass);
	std::cout << "Constructed ScavTrap\n";
	std::cout << "Roar Roar!! " << "\n";
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructed ScavTrap\n";
	std::cout << "NOOOOO NOT ME!! " << "\n";
}
