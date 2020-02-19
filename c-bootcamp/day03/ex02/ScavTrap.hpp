#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:

	void challengeNewcomer(std::string const & target);

	ScavTrap( std::string const & name );
	ScavTrap( const ScavTrap& cc );
	ScavTrap& operator= ( const ScavTrap& cc );
	~ScavTrap();

};

#endif // SCAVTRAP_HPP
