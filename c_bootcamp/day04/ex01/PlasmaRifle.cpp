
#include "PlasmaRifle.hpp"
#include "AWeapon.hpp"

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *\n";
}

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 21, 5) {
}

PlasmaRifle& PlasmaRifle::operator=( const PlasmaRifle& cc ) {
	AWeapon::operator=(cc);
	return *this;
}

PlasmaRifle::PlasmaRifle( const PlasmaRifle& cc ) {
	*this = cc;
}

PlasmaRifle::~PlasmaRifle() {
}
