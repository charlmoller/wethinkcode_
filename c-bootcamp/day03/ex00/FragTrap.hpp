#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

class FragTrap {

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
	void vaulthunter_dot_exe(std::string const & target);

	FragTrap( std::string const & name );
	FragTrap( const FragTrap& cc );
	FragTrap& operator= ( const FragTrap& cc );
	~FragTrap();

};


#endif // FRAGTRAP_HPP
