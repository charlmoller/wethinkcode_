#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy {

private:

	int hp;
	std::string type;
	
public:

	const std::string& getType() const;
	int getHP() const;
	virtual void takeDamage(int);
	Enemy(int hp, std::string const & type);
	Enemy( const Enemy& cc );
	Enemy& operator= ( const Enemy& cc );
	Enemy();
	virtual ~Enemy();

};

#endif // ENEMY_HPP
