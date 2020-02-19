#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include <cmath>
#include <string>
#include <iostream>
#include <time.h>
#include <thread>
#include <unistd.h>
#include <sys/time.h>
#include <locale.h>
#include "Collider.hpp"
#include "Player.hpp"

#define BULLET_CLIP (1000)
#define BULLET_CLIP_ENEMY (5000)
#define ENEMIES (1000)

class Game {
private:
    int weaponCooldown;
    std::string stars;
    int width;
    int height;
    WINDOW* win;
    Player player;
    Collider bullets[BULLET_CLIP];
    Collider enemies[ENEMIES];
    Collider enemyBullets[BULLET_CLIP_ENEMY];
    int score;
    int difficulty;

public:
    Player& getPlayer(void);
    WINDOW* gameWin();
    int getDifficulty(void);
    int getWidth(void);
    int getScore(void);
    void render(int s);
    void update(void);
    void updatePlayer(void);
    void collide(void);
    void clipPlayer(void);
    void shoot(void);
    int getInactiveBullet(void);
    int getInactiveBulletE(void);
    void updateBullets(void);
    void updateEnemies(void);
    Game();
    ~Game();
    Game(const Game& cc);
    Game& operator=(const Game& cc);
};

#endif