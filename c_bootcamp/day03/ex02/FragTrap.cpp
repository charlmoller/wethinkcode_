
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int const INIT_HEALTH = 100;
int const INIT_HEALTH_MAX = 100;
int const INIT_ENERGY = 100;
int const INIT_ENERGY_MAX = 100;
int const INIT_LEVEL = 1;
int const INIT_MELEE_DAMAGE = 30;
int const INIT_RANGE_DAMAGE = 20;
int const INIT_ARMOR = 5;
int const ENERGY_COST_VAULTHUNTER = 25;

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	std::string attacks[] = {
		"knifed",
		"shot",
		"stabbed",
		"punched",
		"bombed"
	};
	if (getEnergy() >= ENERGY_COST_VAULTHUNTER) {
		setEnergy( getEnergy() - ENERGY_COST_VAULTHUNTER );
		std::cout << getName() << " " << attacks[rand() % 5] << " " << target << "\n";
	}
}

FragTrap::FragTrap( std::string const & s ) : ClapTrap(s) {
	std::cout << "Constructed FragTrap " << s << "\n";
	std::cout << "bzzzeeeepp BEp BEEPZ BEEP. FRAGTRAP ACTIVATED!" << "\n";
	setHealth(INIT_HEALTH);
	setHealthMax(INIT_HEALTH_MAX);
	setEnergy(INIT_ENERGY);
	setEnergyMax(INIT_ENERGY_MAX);
	setLevel(INIT_LEVEL);
	setMeleeDamage(INIT_MELEE_DAMAGE);
	setRangedDamage(INIT_RANGE_DAMAGE);
	setArmor(INIT_ARMOR);
}

FragTrap::FragTrap( const FragTrap &cc ) : ClapTrap(cc) {
	std::cout << "Constructed FragTrap\n";
	std::cout << "bzzzeeeepp BEp BEEPZ BEEP. FRAGTRAP ACTIVATED!" << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& ass) {
	ClapTrap::operator=(ass);
	std::cout << "Constructed FragTrap\n";
	std::cout << "bzzzeeeepp BEp BEEPZ BEEP. FRAGTRAP ACTIVATED!" << "\n";
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "Destructed FragTrap " << getName() << "\n";
}
