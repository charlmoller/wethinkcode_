
#include <iostream>
#include <ostream>
#include "Fixed.class.hpp"

const int Fixed::bits = 8;

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
    return (a.getRawBits() > b.getRawBits() ? a : b); 
}
Fixed& Fixed::min( Fixed& a, Fixed& b ) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}
Fixed& Fixed::max( Fixed& a, Fixed& b ) {
    return (a.getRawBits() > b.getRawBits() ? a : b); 
}

int Fixed::getRawBits( void ) const {
    return this->val;
}

void Fixed::setRawBits( int const raw ) {
    this->val = raw;
}

float Fixed::toFloat( void ) const {
    return ((float) this->val) / (1 << Fixed::bits);
}

int Fixed::toInt( void ) const {
    // just shift off all the non-integer bits
    return this->val >> Fixed::bits;
}

Fixed::Fixed( const Fixed& cc ) {
    val = cc.val;
}

Fixed::Fixed( const int i ) {
    this->val = i << Fixed::bits;
}

Fixed::Fixed( const float f ) {
    // convert 123.321 to 123321000...
    this->val = roundf(f * (1 << Fixed::bits));
}

Fixed::Fixed() : val(0) {
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=( const Fixed& ass ) {
    if (this != &ass)
        val = ass.val;
    return *this;
}

Fixed& Fixed::operator=( int i ) {
    this->val = i << Fixed::bits;
    return *this;
}

Fixed& Fixed::operator=( float f ) {
    this->val = roundf(f * (1 << Fixed::bits));
    return *this;
}

std::ostream& operator<<( std::ostream& out, const Fixed& fix ) {
    out << fix.toFloat();
    return out;
}

bool Fixed::operator==( const Fixed& rhs ) {
    return this->val == rhs.val;
}

bool Fixed::operator!=( const Fixed& rhs ) {
    return !(*this == rhs);
}

bool Fixed::operator>( const Fixed& rhs ) {
    return this->val > rhs.val;
}

bool Fixed::operator>=( const Fixed& rhs ) {
    return this->val >= rhs.val;
}

bool Fixed::operator<( const Fixed& rhs ) {
    return this->val < rhs.val;
}

bool Fixed::operator<=( const Fixed& rhs ) {
    return this->val <= rhs.val;
}

Fixed& Fixed::operator+=( const Fixed& rhs ) {
    this->val += rhs.val;
    return (*this);
}

Fixed& Fixed::operator-=( const Fixed& rhs ) {
    this->val -= rhs.val;
    return (*this);
}

Fixed& Fixed::operator*=( const Fixed& rhs ) {
// Tradeoff between time and accuracy here
    // The normal version would look like this
    // but it's very imprecise:
    //this->val = (this->val * rhs.val) >> Fixed::bits;
    
    // Where this is more accurate but the pdf might complain
    long v1 = (long)this->val;
    long v2 = (long)rhs.val;
    this->val = (v1 * v2) >> Fixed::bits;
    return (*this);
}

Fixed& Fixed::operator/=( const Fixed& rhs ) {
    // This is even worse, very inaccurate
    //this->val = (this->val << Fixed::bits) / rhs.val;
    
    // Again, the pdf might complain about this, but it's more precise
    long v1 = (long)this->val << (Fixed::bits * 2);
    long v2 = (long)rhs.val << Fixed::bits;
    this->val = (v1 / v2);
    return (*this);
}

const Fixed& Fixed::operator+( const Fixed& rhs ) {
    return *this += rhs;
}

const Fixed& Fixed::operator-( const Fixed& rhs ) {
    return *this -= rhs;
}

const Fixed& Fixed::operator*( const Fixed& rhs ) {
    return *this *= rhs;
}

const Fixed& Fixed::operator/( const Fixed& rhs ) {
    return *this /= rhs;
}

Fixed& Fixed::operator++() {
    this->val++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    Fixed::operator++();
    return tmp;
}

Fixed& Fixed::operator--() {
    this->val--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    Fixed::operator--();
    return tmp;
}
