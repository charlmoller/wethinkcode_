
#include <iostream>
#include "Fixed.class.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "Larger of a and b : " << Fixed::max( a, b ) << std::endl;
	
	return 0;
}