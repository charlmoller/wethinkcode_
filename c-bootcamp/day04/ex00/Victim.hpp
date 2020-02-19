
#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim {

private:
	std::string name;

public:

	void getPolymorphed(void) const;
	const std::string& getName() const;
	Victim(std::string);
	Victim();
	Victim( const Victim& );
	Victim& operator= ( const Victim& );
	~Victim();

};

std::ostream& operator<< (std::ostream& out, const Victim& cc );

#endif // VICTIM_HPP
