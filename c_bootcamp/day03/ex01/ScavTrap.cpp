
#include <iostream>
#include <string>
#include <cstdlib>
#include "ScavTrap.hpp"

#define CLAMP_MIN(val, min) if (val < min) val = min; 
#define CLAMP_MAX(val, max) if (val > max) val = max; 

int const INIT_HEALTH = 100;
int const INIT_HEALTH_MAX = 100;
int const INIT_ENERGY = 50;
int const INIT_ENERGY_MAX = 50;
int const INIT_LEVEL = 1;
int const INIT_MELEE_DAMAGE = 20;
int const INIT_RANGE_DAMAGE = 15;
int const INIT_ARMOR = 3;

void ScavTrap::rangedAttack(std::string const & target) {
	std::cout << name << " spitted acid at " << target << "\n";
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << name << " charged " << target << "\n";
}

void ScavTrap::takeDamage(unsigned int amount) {
	int a = (int) amount;
	a = a < armor ? 0 : a - armor ;
	a = a > healthMax ? healthMax : a;
	health -= a;
	CLAMP_MIN(health, 0);
	std::cout << name << " took " << (a - health) * -1 << " damage\n";
}

void ScavTrap::beRepaired(unsigned int amount) {
	int a = (int) amount;
	a = a > healthMax ? healthMax : a;
	health += a;
	CLAMP_MAX(health, healthMax);
	std::cout << name << " repaired " << a << " health\n";
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	std::string challenge[] = {
		"to a duel",
		"to a battle",
		"to a stare off",
		"to a thumb war",
		"sword fight"
	};
	std::cout << name << " challenges " << target << " " << challenge[rand() % 5] << "\n";
}

ScavTrap::ScavTrap( std::string const & s ) : name(s) {
	std::cout << "Constructed ScavTrap " << s << "\n";
	std::cout << "Roar Roar!! " << "\n";
	health       = INIT_HEALTH;
	healthMax    = INIT_HEALTH_MAX;
	energy       = INIT_ENERGY;
	energyMax    = INIT_ENERGY_MAX;
	level        = INIT_LEVEL;
	meleeDamage  = INIT_MELEE_DAMAGE;
	rangedDamage = INIT_RANGE_DAMAGE;
	armor        = INIT_ARMOR;
}

ScavTrap::ScavTrap( const ScavTrap &cc ) {
	std::cout << "Constructed ScavTrap " << cc.name << "\n";
	std::cout << "Roar Roar!! " << "\n";
	health       = cc.health;
	healthMax    = cc.healthMax;
	energy       = cc.energy;
	energyMax    = cc.energyMax;
	level        = cc.level;
	meleeDamage  = cc.meleeDamage;
	rangedDamage = cc.rangedDamage;
	armor        = cc.armor;
	name         = cc.name;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ass) {
	std::cout << "Constructed ScavTrap " << ass.name << "\n";
	std::cout << "Roar Roar!! " << "\n";
	health       = ass.health;
	healthMax    = ass.healthMax;
	energy       = ass.energy;
	energyMax    = ass.energyMax;
	level        = ass.level;
	meleeDamage  = ass.meleeDamage;
	rangedDamage = ass.rangedDamage;
	armor        = ass.armor;
	name         = ass.name;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructed ScavTrap " << name << "\n";
	std::cout << "NOOOOO NOT ME!! " << "\n";
}
