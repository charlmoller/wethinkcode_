
#include "RadScorpion.hpp"
#include "Enemy.hpp"

RadScorpion::RadScorpion(int h, std::string const & t) : 
	Enemy(h, t) {
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion( const RadScorpion& cc ) {
	*this = cc;
}

RadScorpion& RadScorpion::operator=( const RadScorpion& cc ) {
	Enemy::operator=(cc);
	return *this;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *\n";
}
