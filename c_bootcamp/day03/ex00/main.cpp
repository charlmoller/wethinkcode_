
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <sys/time.h>
#include "FragTrap.hpp"

int main( void ) {

	struct timeval ts; 
	gettimeofday(&ts, NULL);
	srand( ts.tv_usec );
	
	//TODO TEST FRAGTRAP
	FragTrap a( "A" );
	FragTrap b( a );
	FragTrap c = b;
	b.takeDamage(30);
	b.takeDamage(30);
	b.takeDamage(20);
	b.takeDamage(20);
	b.beRepaired(20);
	b.rangedAttack("test person");
	b.meleeAttack("test person");
	b.vaulthunter_dot_exe("test person");
	b.vaulthunter_dot_exe("test person");
	b.vaulthunter_dot_exe("test person");
	b.vaulthunter_dot_exe("test person");
	
	return 0;
}