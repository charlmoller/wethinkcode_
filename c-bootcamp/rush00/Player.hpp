#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Player {
private:
    float y;
    float x;
    float yv;
    float xv;
    int health;
    int weaponLevel;

public:
    void update(void);
    void left(void);
    void right(void);
    void up(void);
    void down(void);
    void moveLeft(void);
    void moveRight(void);
    void moveDown(void);
    void moveUp(void);
    int getX(void);
    int getY(void);
    int getWeaponLevel(void);
    int getHealth(void);
    void updateWeaponLevel(int inc);
    Player();
    ~Player();
    Player(int mapHeight, int mapWidth);
    Player(const Player& cc);
    Player& operator=(const Player& cc);
};

#endif