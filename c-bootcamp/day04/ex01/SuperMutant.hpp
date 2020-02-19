#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include <iostream>
#include <string>
#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

	void takeDamage(int);
	SuperMutant(int hp, std::string const & type);
	SuperMutant( const SuperMutant& cc );
	SuperMutant& operator= ( const SuperMutant& cc );
	SuperMutant();
	~SuperMutant();

};

#endif // SUPERMUTANT_HPP
