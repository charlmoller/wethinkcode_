
#include "Victim.hpp"

void Victim::getPolymorphed(void) const {
	std::cout << name << " has been turned into a pink pony!\n";
}

const std::string& Victim::getName(void) const {
	return name;
}

Victim::Victim( std::string n ) : name(n) {
	std::cout << "Some random victim called " << n << " just popped !\n";
}

Victim::Victim( const Victim& cc ) {
	name = cc.name;
}

Victim& Victim::operator= ( const Victim& cc ) {
	name = cc.getName();
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Victim& cc ) {
	out << "I'm " << cc.getName() << " and I like otters !\n";
	return out;
}

Victim::~Victim() {
	std::cout << "Victim " << name;
	std::cout << " just died for no apparent reason !\n";
}
