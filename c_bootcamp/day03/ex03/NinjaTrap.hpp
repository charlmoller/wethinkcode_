#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class NinjaTrap: public ClapTrap {

public:

	void ninjaShoebox( const NinjaTrap& cc );
	void ninjaShoebox( const ScavTrap& cc );
	void ninjaShoebox( const FragTrap& cc );

	NinjaTrap( std::string const & name );
	NinjaTrap( const NinjaTrap& cc );
	NinjaTrap& operator= ( const NinjaTrap& cc );
	~NinjaTrap();

};

#endif // NINJATRAP_HPP
