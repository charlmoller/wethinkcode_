#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

class ScavTrap {

private:

	int health;
	int healthMax;
	int energy;
	int energyMax;
	int level;
	int meleeDamage;
	int rangedDamage;
	int armor;
	std::string name;

public:

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const & target);

	ScavTrap( std::string const & name );
	ScavTrap( const ScavTrap& cc );
	ScavTrap& operator= ( const ScavTrap& cc );
	~ScavTrap();

};


#endif // SCAVTRAP_HPP
