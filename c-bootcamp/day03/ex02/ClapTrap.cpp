
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"

#define CLAMP_MIN(val, min) if (val < min) val = min; 
#define CLAMP_MAX(val, max) if (val > max) val = max; 

void ClapTrap::rangedAttack(std::string const & target) {
	std::cout << name << " ranged attacked " << target << "\n";
}

void ClapTrap::meleeAttack(std::string const & target) {
	std::cout << name << " melee attacked " << target << "\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	int a = (int) amount;
	a = a < armor ? 0 : a - armor ;
	a = a > healthMax ? healthMax : a;
	health -= a;
	CLAMP_MIN(health, 0);
	std::cout << name << " took " << (a - health) * -1 << " damage\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	int a = (int) amount;
	a = a > healthMax ? healthMax : a;
	health += a;
	CLAMP_MAX(health, healthMax);
	std::cout << name << " repaired " << a << " health\n";
}

ClapTrap::ClapTrap( std::string const & s ) : name(s) {
	std::cout << "Constructed ClapTrap " << s << "\n";
}

ClapTrap::ClapTrap( const ClapTrap &cc ) {
	std::cout << "Constructed ClapTrap " << cc.name << "\n";
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

ClapTrap& ClapTrap::operator=(const ClapTrap& ass) {
	std::cout << "Constructed ClapTrap " << ass.name << "\n";
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

ClapTrap::~ClapTrap() {
	std::cout << "Destructed ClapTrap " << name << "\n";
}

// don't judge me
void ClapTrap::setHealth(int v)       { health = v; }
void ClapTrap::setHealthMax(int v)    { healthMax = v; }
void ClapTrap::setEnergy(int v)       { energy = v; }
void ClapTrap::setEnergyMax(int v)    { energyMax = v; }
void ClapTrap::setLevel(int v)        { level = v; }
void ClapTrap::setMeleeDamage(int v)  { meleeDamage = v; }
void ClapTrap::setRangedDamage(int v) { rangedDamage = v; }
void ClapTrap::setArmor(int v)        { armor = v; }
void ClapTrap::setName(std::string s) { name = s; }
int         ClapTrap::getHealth(void) const       { return health; }
int         ClapTrap::getHealthMax(void) const    { return healthMax; }
int         ClapTrap::getEnergy(void) const       { return energy; }
int         ClapTrap::getEnergyMax(void) const    { return energyMax; }
int         ClapTrap::getLevel(void) const        { return level; }
int         ClapTrap::getMeleeDamage(void) const  { return meleeDamage; }
int         ClapTrap::getRangedDamage(void) const { return rangedDamage; }
int         ClapTrap::getArmor(void) const        { return armor; }
std::string ClapTrap::getName(void) const         { return name; }
