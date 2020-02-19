
#include "PowerFist.hpp"
#include "AWeapon.hpp"

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *\n";
}

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8) {
}

PowerFist& PowerFist::operator=( const PowerFist& cc ) {
	AWeapon::operator=(cc);
	return *this;
}

PowerFist::PowerFist( const PowerFist& cc ) {
	*this = cc;
}

PowerFist::~PowerFist() {
}
