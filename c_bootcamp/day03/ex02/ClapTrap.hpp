#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {

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

	int getHealth(void) const;
	int getHealthMax(void) const;
	int getEnergy(void) const;
	int getEnergyMax(void) const;
	int getLevel(void) const;
	int getMeleeDamage(void) const;
	int getRangedDamage(void) const;
	int getArmor(void) const;
	std::string getName(void) const;
	void setHealth(int);
	void setHealthMax(int);
	void setEnergy(int);
	void setEnergyMax(int);
	void setLevel(int);
	void setMeleeDamage(int);
	void setRangedDamage(int);
	void setArmor(int);
	void setName(std::string);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);

	ClapTrap( std::string const & name );
	ClapTrap( const ClapTrap& cc );
	ClapTrap& operator= ( const ClapTrap& cc );
	~ClapTrap();

};


#endif // CLAPTRAP_HPP
