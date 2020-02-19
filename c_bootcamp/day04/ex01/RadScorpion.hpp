#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include <iostream>
#include <string>
#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion(int hp, std::string const & type);
	RadScorpion( const RadScorpion& cc );
	RadScorpion& operator= ( const RadScorpion& cc );
	RadScorpion();
	~RadScorpion();

};

#endif // RADSCORPION_HPP
