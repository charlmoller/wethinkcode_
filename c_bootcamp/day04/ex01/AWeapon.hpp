#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon {

private:
	std::string name;
	int apcost;
	int damage;

public:

	AWeapon(std::string const & name, int apcost, int damage);
	const std::string& getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
	AWeapon( const AWeapon& );
	AWeapon& operator= ( const AWeapon& );
	AWeapon();
	~AWeapon();

};

#endif // AWEAPON_HPP
