
#include <iostream>
#include <ostream>
#include "Fixed.class.hpp"

const int Fixed::bits = 8;

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return this->val;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}

float Fixed::toFloat( void ) const {
	return ((float) this->val) / (1 << Fixed::bits);
}

int Fixed::toInt( void ) const {
	return this->val >> Fixed::bits;
}

Fixed::Fixed( const int val ) {
	std::cout << "Int constructor called\n";
	this->val = val << Fixed::bits;
}

Fixed::Fixed( const float val ) {
	std::cout << "Float constructor called\n";
	this->val = roundf(val * (1 << Fixed::bits));
}

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed& cc ) {
	std::cout << "Copy constructor called\n";	
	val = cc.val;
}

Fixed& Fixed::operator= ( const Fixed& ass ) {
	std::cout << "Assignation operator called\n";
	val = ass.val;
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Fixed& fix) {
	out << fix.toFloat();
	return out;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

