
#include "Victim.hpp"
#include "Peon.hpp"

Peon::Peon( std::string n ) : Victim(n) {
	std::cout << "Zog zog.\n";
}

Peon::Peon( const Peon& cc ) : Victim(cc) {
	std::cout << "Zog zog.\n";
}

Peon& Peon::operator= ( const Peon& cc ) {
	Victim::operator=(cc);
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Peon& cc) {
	out << "I am " << cc.getName();
	out << " and I like otters !\n";
	return out;
}

Peon::~Peon() {
	std::cout << "Bleuark...\n";
}
