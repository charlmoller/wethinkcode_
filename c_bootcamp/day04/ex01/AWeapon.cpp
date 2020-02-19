
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & n, int a, int d) :
	name(n), apcost(a), damage(d) {
}

const std::string& AWeapon::getName() const {
	return name;
}

int AWeapon::getAPCost() const {
	return apcost;
}

int AWeapon::getDamage() const {
	return damage;
}

AWeapon::AWeapon( const AWeapon& cc ) {
	*this = cc;
}

AWeapon& AWeapon::operator=( const AWeapon& cc ) {
	name = cc.name;
	apcost = cc.apcost;
	damage = cc.damage;
	return *this;
}

AWeapon::AWeapon() : name(""), apcost(0), damage(0) {
}

AWeapon::~AWeapon() {
}
