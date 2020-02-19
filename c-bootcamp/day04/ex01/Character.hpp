
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

private:
	int ap;
	std::string name;
	AWeapon* weapon;

public:

	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	const std::string& getName() const;
	int getAP() const;
	const AWeapon* getWeapon() const;
	Character(std::string const & name);
	Character();
	Character( const Character& );
	Character& operator= ( const Character& );
	~Character();

};

std::ostream& operator<< (std::ostream& out, const Character& );

#endif // CHARACTER_HPP
