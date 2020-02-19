#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

// includes

class Fixed {

private:
	static const int bits; // set to 8
	int val;

public:

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	Fixed();
	Fixed( const Fixed& cc );
	// Fixed( const Fixed& cc ) : val(cc.val); 
	Fixed& operator= ( const Fixed& cc );
	// Fixed &operator= ( const Fixed& cc ) : val(cc.val); 	
	~Fixed();

// From now on, each class you write MUST be in canonical form : At least one default
// constructor, a copy contructor, an assignation operator overload and a destructor.

};


#endif // FIXED_CLASS_HPP
