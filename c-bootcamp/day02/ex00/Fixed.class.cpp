
#include <iostream>
#include "Fixed.class.hpp"

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return this->val;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed& cc ) {
	std::cout << "Copy constructor called\n";	
	val = cc.val;
}

Fixed& Fixed::operator=(const Fixed& ass) {
	std::cout << "Assignation operator called\n";
	val = ass.val;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
