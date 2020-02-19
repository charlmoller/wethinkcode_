
#include "Enemy.hpp"

const std::string& Enemy::getType() const {
	return type;
}

int Enemy::getHP() const {
	return hp;
}

void Enemy::takeDamage(int d) {
	if (d <= 0) {
		if (d > hp)
			hp = 0;
		else
			hp -= d;
	}
	if (hp < 0)
		hp = 0;
}

Enemy::Enemy(int h, std::string const & t) {
	hp = h;
	type = t;
}

Enemy::Enemy( const Enemy& cc ) {
	*this = cc;
}

Enemy& Enemy::operator=( const Enemy& cc) {
	hp = cc.hp;
	type = cc.type;
	return *this;
}

Enemy::Enemy() {
	hp = 0;
	type = "";
}

Enemy::~Enemy() {
}
