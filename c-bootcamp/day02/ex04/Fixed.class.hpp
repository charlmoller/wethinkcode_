#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {

private:
    static const int bits;
    int val;

public:

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    Fixed();
    Fixed( const Fixed& cc );
    Fixed( const int val );
    Fixed( const float val );
    ~Fixed();

    Fixed& operator=( const Fixed& cc );
    Fixed& operator=( int i );
    Fixed& operator=( float f );
    friend std::ostream& operator<<( std::ostream& out, const Fixed& fix );
    
    bool operator==( const Fixed& rhs );
    bool operator!=( const Fixed& rhs );
    bool operator>( const Fixed& rhs );
    bool operator>=( const Fixed& rhs );
    bool operator<( const Fixed& rhs );
    bool operator<=( const Fixed& rhs );
  
    // A Caltech professor suggests implementing compound assignment operators ...
    Fixed& operator+=( const Fixed &rhs );
    Fixed& operator-=( const Fixed &rhs );
    Fixed& operator*=( const Fixed &rhs );
    Fixed& operator/=( const Fixed &rhs );

    // ... and using them to handle arithmetic operators
    const Fixed& operator+( const Fixed& rhs );
    const Fixed& operator-( const Fixed& rhs );
    const Fixed& operator*( const Fixed& rhs );
    const Fixed& operator/( const Fixed& rhs );
    
    Fixed& operator++();
    Fixed operator++( int );
    Fixed& operator--();
    Fixed operator--( int );

    static Fixed& min( Fixed&, Fixed& );
    static Fixed& max( Fixed&, Fixed& ); 
    static const Fixed& min( const Fixed&, const Fixed& );
    static const Fixed& max( const Fixed&, const Fixed& ); 

};


#endif // FIXED_CLASS_HPP
