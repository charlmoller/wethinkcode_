
#include "Sorcerer.hpp"

void Sorcerer::polymorph( const Victim& vic ) const {
	vic.getPolymorphed();
}

const std::string& Sorcerer::getName(void) const {
	return name;
}

const std::string& Sorcerer::getTitle(void) const {
	return title;
}

Sorcerer::Sorcerer( std::string n, std::string t ) : name(n), title(t) {
	std::cout << n << ", " << t << ", is born !\n";
}

Sorcerer::Sorcerer( const Sorcerer& cc ) {
	name = cc.name;
	title = cc.title;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& cc) {
	name = cc.name;
	title = cc.title;
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Sorcerer& cc) {
	out << "I am " << cc.getName() << ", ";
	out << cc.getTitle() << ", and I like ponies !\n";
	return out;
}

Sorcerer::~Sorcerer() {
	std::cout << name << ", " << title << ", is dead.";
	std::cout << " Consequences will never be the same !\n";
}
