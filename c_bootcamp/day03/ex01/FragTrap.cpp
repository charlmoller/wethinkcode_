
#include <iostream>
#include <string>
#include <cstdlib>
#include "FragTrap.hpp"

#define CLAMP_MIN(val, min) if (val < min) val = min; 
#define CLAMP_MAX(val, max) if (val > max) val = max; 

int const INIT_HEALTH = 100;
int const INIT_HEALTH_MAX = 100;
int const INIT_ENERGY = 100;
int const INIT_ENERGY_MAX = 100;
int const INIT_LEVEL = 1;
int const INIT_MELEE_DAMAGE = 30;
int const INIT_RANGE_DAMAGE = 20;
int const INIT_ARMOR = 5;
int const ENERGY_COST_VAULTHUNTER = 25;

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << name << " ranged attacked " << target << "\n";
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << name << " melee attacked " << target << "\n";
}

void FragTrap::takeDamage(unsigned int amount) {
	int a = (int) amount;
	a = a < armor ? 0 : a - armor ;
	a = a > healthMax ? healthMax : a;
	health -= a;
	CLAMP_MIN(health, 0);
	std::cout << name << " took " << (a - health) * -1 << " damage\n";
}

void FragTrap::beRepaired(unsigned int amount) {
	int a = (int) amount;
	a = a > healthMax ? healthMax : a;
	health += a;
	CLAMP_MAX(health, healthMax);
	std::cout << name << " repaired " << a << " health\n";
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	std::string attacks[] = {
		"knifed",
		"shot",
		"stabbed",
		"punched",
		"bombed"
	};
	if (energy >= ENERGY_COST_VAULTHUNTER) {
		energy -= ENERGY_COST_VAULTHUNTER;
		std::cout << name << " " << attacks[rand() % 5] << " " << target << "\n";
	}
}

FragTrap::FragTrap( std::string const & s ) : name(s) {
	std::cout << "Constructed FragTrap " << s << "\n";
	std::cout << "bzzzeeeepp BEp BEEPZ BEEP. FRAGTRAP ACTIVATED!" << "\n";
	health       = INIT_HEALTH;
	healthMax    = INIT_HEALTH_MAX;
	energy       = INIT_ENERGY;
	energyMax    = INIT_ENERGY_MAX;
	level        = INIT_LEVEL;
	meleeDamage  = INIT_MELEE_DAMAGE;
	rangedDamage = INIT_RANGE_DAMAGE;
	armor        = INIT_ARMOR;
}

FragTrap::FragTrap( const FragTrap &cc ) {
	std::cout << "Constructed FragTrap " << cc.name << "\n";
	std::cout << "bzzzeeeepp BEp BEEPZ BEEP. FRAGTRAP ACTIVATED!" << "\n";
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

FragTrap& FragTrap::operator=(const FragTrap& ass) {
	std::cout << "Constructed FragTrap " << ass.name << "\n";
	std::cout << "bzzzeeeepp BEp BEEPZ BEEP. FRAGTRAP ACTIVATED!" << "\n";
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

FragTrap::~FragTrap() {
	std::cout << "Destructed FragTrap " << name << "\n";
	std::cout << "NOOOOO NOT NOW IT\'S TOO EARLY!! " << "\n";
}
