
#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"

void Character::recoverAP() {
	ap += 10;
	if (ap > 40)
		ap = 40;
}

void Character::equip(AWeapon* w) {
	weapon = w;
}

void Character::attack(Enemy* e) {
	std::cout << name << " attacks " << e->getType();
	std::cout << " with a " << weapon->getName() << "\n";
	weapon->attack();
	e->takeDamage(weapon->getDamage());
	std::cout << e->getHP() << "\n";
	if (e->getHP() <= 0)
		delete e;
}

const std::string& Character::getName() const {
	return name;
}

int Character::getAP() const {
	return ap;
}

const AWeapon* Character::getWeapon() const {
	return weapon;
}

std::ostream& operator<< (std::ostream& out, const Character& cc ) {
	if (cc.getWeapon() == 0) {
		out << cc.getName() << " has " << cc.getAP();
		out << " AP and is unarmed\n";
	} else {
		out << cc.getName() << " has " << cc.getAP();
		out << " AP and wields a " << cc.getWeapon()->getName();
		out << "\n";
	}
	return out;
}

Character::Character(std::string const & n) : name(n) {
	ap = 40;
	weapon = 0;
}

Character::Character( const Character& cc ) {
	*this = cc;
}

Character& Character::operator=(const Character& cc) {
	name = cc.name;
	ap = cc.ap;
	weapon = cc.weapon;
	return *this;
}

Character::~Character() {
}


