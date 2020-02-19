
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <sys/time.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	struct timeval ts; 
	gettimeofday(&ts, NULL);
	srand( ts.tv_usec );
	
	//TODO TEST FRAGTRAP
	FragTrap a( "((myfragtrap))" );
	FragTrap b( a );
	FragTrap c = b;
	b.takeDamage(30);
	b.takeDamage(30);
	b.beRepaired(20);
	b.rangedAttack("test person");
	b.meleeAttack("test person");
	b.vaulthunter_dot_exe("test person");
	b.vaulthunter_dot_exe("test person");
	b.vaulthunter_dot_exe("test person");
	b.vaulthunter_dot_exe("test person");
	
	ScavTrap as( "((myscavtrap))" );
	ScavTrap bs( as );
	ScavTrap cs = bs;
	bs.takeDamage(30);
	bs.takeDamage(30);
	bs.beRepaired(20);
	bs.rangedAttack("test person");
	bs.meleeAttack("test person");
	bs.challengeNewcomer("test person");
	bs.challengeNewcomer("test person");
	bs.challengeNewcomer("test person");
	bs.challengeNewcomer("test person");

	return 0;
}