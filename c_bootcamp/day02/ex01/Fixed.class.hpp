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
	Fixed& operator= ( const Fixed &cc );
	friend std::ostream& operator<< (std::ostream& out, const Fixed& fix);
	~Fixed();

};


#endif // FIXED_CLASS_HPP
