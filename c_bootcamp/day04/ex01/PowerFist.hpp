#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <string>
#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:

	void attack() const;
	PowerFist(std::string const & name, int apcost, int damage);
	PowerFist( const PowerFist& );
	PowerFist& operator= ( const PowerFist& );
	PowerFist();
	~PowerFist();

};

#endif // POWERFIST_HPP
