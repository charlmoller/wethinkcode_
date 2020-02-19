
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

int const INIT_HEALTH = 60;
int const INIT_HEALTH_MAX = 60;
int const INIT_ENERGY = 120;
int const INIT_ENERGY_MAX = 120;
int const INIT_LEVEL = 1;
int const INIT_MELEE_DAMAGE = 60;
int const INIT_RANGE_DAMAGE = 5;
int const INIT_ARMOR = 0;

void NinjaTrap::ninjaShoebox( const NinjaTrap& cc ) {
	std::cout << getName() << "chops " << cc.getName() << "\n"; 
}
void NinjaTrap::ninjaShoebox( const ScavTrap& cc ) {
	std::cout << getName() << " attacks a scavtrap " << cc.getName() << "\n"; 
}
void NinjaTrap::ninjaShoebox( const FragTrap& cc ) {
	std::cout << getName() << " attacks a fragtrap " << cc.getName() << "\n"; 
}

NinjaTrap::NinjaTrap( std::string const & s ) : ClapTrap(s) {
	std::cout << "Constructed NinjaTrap " << s << "\n";
	std::cout << "CHOP SUEYEYEY. NinjaTrap ACTIVATED!" << "\n";
	setHealth(INIT_HEALTH);
	setHealthMax(INIT_HEALTH_MAX);
	setEnergy(INIT_ENERGY);
	setEnergyMax(INIT_ENERGY_MAX);
	setLevel(INIT_LEVEL);
	setMeleeDamage(INIT_MELEE_DAMAGE);
	setRangedDamage(INIT_RANGE_DAMAGE);
	setArmor(INIT_ARMOR);
}

NinjaTrap::NinjaTrap( const NinjaTrap &cc ) : ClapTrap(cc) {
	std::cout << "Constructed NinjaTrap\n";
	std::cout << "CHOP SUEYEYEY. NinjaTrap ACTIVATED!" << "\n";
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& ass) {
	ClapTrap::operator=(ass);
	std::cout << "Constructed NinjaTrap\n";
	std::cout << "CHOP SUEYEYEY. NinjaTrap ACTIVATED!" << "\n";
	return *this;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "Destructed NinjaTrap " << getName() << "\n";
	std::cout << "CHOP!" << "\n";	
}
