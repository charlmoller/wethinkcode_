
#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include <string>

class Peon : public Victim {

public:
	Peon( std::string );
	Peon( const Peon& );
	Peon& operator= ( const Peon& );
	~Peon();
};

std::ostream& operator<< (std::ostream& out, const Peon& cc );

#endif // PEON_HPP
