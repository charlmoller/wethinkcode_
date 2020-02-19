
#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer {

private:
	std::string name;
	std::string title;

public:


	void polymorph( const Victim& ) const;
	const std::string& getName() const;
	const std::string& getTitle() const;
	Sorcerer(std::string, std::string);
	Sorcerer();
	Sorcerer( const Sorcerer& );
	Sorcerer& operator= ( const Sorcerer& );
	~Sorcerer();

};

std::ostream& operator<< (std::ostream& out, const Sorcerer& cc);

#endif // SORCERER_HPP
