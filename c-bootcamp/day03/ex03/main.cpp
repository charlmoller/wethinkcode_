
#include <iostream>
#include <typeinfo>
#include <sys/time.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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
	b.takeDamage(20);
	b.takeDamage(20);
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
	bs.takeDamage(20);
	bs.takeDamage(20);
	bs.beRepaired(20);
	bs.rangedAttack("test person");
	bs.meleeAttack("test person");
	bs.challengeNewcomer("test person");
	bs.challengeNewcomer("test person");
	bs.challengeNewcomer("test person");
	bs.challengeNewcomer("test person");

	NinjaTrap an( "((myninjatrap))" );
	NinjaTrap bn( an );
	NinjaTrap cn = bn;
	bn.takeDamage(30);
	bn.takeDamage(30);
	bn.takeDamage(20);
	bn.takeDamage(20);
	bn.beRepaired(20);
	bn.rangedAttack("test person");
	bn.meleeAttack("test person");
	bn.ninjaShoebox(bs);
	bn.ninjaShoebox(b);
	bn.ninjaShoebox(an);

	return 0;
}
