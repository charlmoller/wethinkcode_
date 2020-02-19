#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include <string>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	void attack() const;
	PlasmaRifle(std::string const & name, int apcost, int damage);
	PlasmaRifle( const PlasmaRifle& );
	PlasmaRifle& operator= ( const PlasmaRifle& );
	PlasmaRifle();
	~PlasmaRifle();

};

#endif // PLASMARIFLE_HPP
