
#include "Player.hpp"

Player::Player(int mapHeight, int mapWidth)
{
    (void)mapWidth;
    weaponLevel = 0;
    health = 3;
    x = 1;
    y = mapHeight / 2;
    yv = 0;
    xv = 0;
}

Player::Player()
{
}

Player::~Player()
{
}

Player& Player::operator=(const Player& ass)
{
    x = ass.x;
    return *this;
}

void Player::moveLeft(void)
{
    this->x--;
}

void Player::moveRight(void)
{
    this->x++;
}

void Player::moveDown(void)
{
    this->y++;;
}

void Player::moveUp(void)
{
    this->y--;
}

void Player::left(void)
{
    this->xv = -1.0;
}

void Player::right(void)
{
    this->xv = 1.0;
}

void Player::down(void)
{
    this->yv = 0.4;
}

void Player::up(void)
{
    this->yv = -0.4;
}

int Player::getX(void)
{
    return x;
}

void Player::update(void)
{
    y += yv;
    yv *= 0.9;
    x += xv;
    xv *= 0.9;
    if (xv > 1.0)
        xv = 1.0;
    if (xv < -1.0)
        xv = -1.0;
    if (yv > 0.5)
        yv = 0.5;
    if (yv < -0.5)
        yv = -0.5;
}

int Player::getY(void)
{
    return y;
}

int Player::getWeaponLevel(void)
{
    return weaponLevel;
}

void Player::updateWeaponLevel(int val)
{
    weaponLevel = val;
}

int Player::getHealth(void)
{
    return health;
}
