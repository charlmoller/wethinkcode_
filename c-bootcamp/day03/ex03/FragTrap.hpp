#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:

	void vaulthunter_dot_exe(std::string const & target);

	FragTrap( std::string const & name );
	FragTrap( const FragTrap& cc );
	FragTrap& operator= ( const FragTrap& cc );
	~FragTrap();

};

#endif // FRAGTRAP_HPP
