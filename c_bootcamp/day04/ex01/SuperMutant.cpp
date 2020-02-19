
#include "SuperMutant.hpp"
#include "Enemy.hpp"

void SuperMutant::takeDamage(int d) {
	d -= 3;
	Enemy::takeDamage(d);
}

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::SuperMutant( const SuperMutant& cc ) {
	*this = cc;
}

SuperMutant& SuperMutant::operator=( const SuperMutant& cc ) {
	Enemy::operator=(cc);
	return *this;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh ...\n";
}
