
#include "Game.hpp"

#define WIDTH (150)
#define HEIGHT (25)
#define WEAPON_COOLDOWN_TIME (2)

Game::Game()
{

    // game
    width = WIDTH;
    height = HEIGHT;
    weaponCooldown = 0;
    difficulty = 0;
    score = 0;
    player = Player(height, width);
    stars = "";
    for (int i = 0; i < width * height; ++i)
        for (int j = 0; j < height; ++j)
            stars += (rand() % 100 > 92) ? "*" : " ";

    // ncurses
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    curs_set(FALSE);
    cbreak();
    //refresh();
    this->win = newwin(height, width, 1, 1);
    //wrefresh(this->win);
}

void Game::update()
{
    updateBullets();
    updateEnemies();
    updatePlayer();
    clipPlayer();
    collide();
    if (score > 2000)
        player.updateWeaponLevel(5);
    else if (score > 1000)
        player.updateWeaponLevel(4);
    else if (score > 500)
        player.updateWeaponLevel(3);
    else if (score > 200)
        player.updateWeaponLevel(2);
    else if (score > 50)
        player.updateWeaponLevel(1);

    for (int i = 0; i < BULLET_CLIP_ENEMY; ++i) {
        if (enemyBullets[i].getActive()) {
            float by = enemyBullets[i].getY();
            float bx = enemyBullets[i].getX();
            float py = player.getY();
            float px = player.getX();
            if ((bx < px + 0.4 && bx > px - 0.4)
                && (by < py + 0.4 && by > py - 0.4))
                difficulty = -100;
        }
    }
    for (int i = 0; i < ENEMIES; ++i) {
        if (enemies[i].getActive()) {
            float ey = enemies[i].getY();
            float ex = enemies[i].getX();
            float py = player.getY();
            float px = player.getX();
            if ((ex < px + 2.2 && ex > px - 1.3)
                && (ey < py + 1.1 && ey > py - 1.1))
                difficulty = -100;
        }
    }
}

void Game::render(int wrap)
{
    mvprintw(height + 1, 1, "Weapon Level : %d", player.getWeaponLevel());
    mvprintw(height + 2, 1, "Difficulty   : %d", difficulty / 100);
    mvprintw(height + 3, 1, "Score.       : %d", score);
    werase(gameWin());
    wattron(gameWin(), COLOR_PAIR(1));
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            mvwprintw(gameWin(), i, j, "%c",
                stars[i * width + ((j + wrap) % width)]);
    wattroff(gameWin(), COLOR_PAIR(1));
    box(gameWin(), 0, 0);

    wattron(gameWin(), COLOR_PAIR(3));
    for (int i = 0; i < ENEMIES; i++) {
        if (enemies[i].getActive()) {
            mvwprintw(gameWin(), enemies[i].getY() - 1, enemies[i].getX() - 2, "--<<}");
            mvwprintw(gameWin(), enemies[i].getY(), enemies[i].getX() - 1, "([]");
            mvwprintw(gameWin(), enemies[i].getY() + 1, enemies[i].getX() - 2, "--<<}");
        }
    }
    for (int i = 0; i < BULLET_CLIP_ENEMY; i++)
        if (enemyBullets[i].getActive())
            mvwprintw(gameWin(), enemyBullets[i].getY(), enemyBullets[i].getX(), "O");
    wattroff(gameWin(), COLOR_PAIR(3));

    wattron(gameWin(), COLOR_PAIR(2));
    for (int i = 0; i < BULLET_CLIP; i++)
        if (bullets[i].getActive())
            mvwprintw(gameWin(), bullets[i].getY(), bullets[i].getX(), "=");
    mvwprintw(gameWin(), roundf(player.getY()), roundf(player.getX()) - 1, ">");
    wattroff(gameWin(), COLOR_PAIR(2));

    //refresh();
    wrefresh(gameWin());
}

void Game::updatePlayer(void)
{
    player.update();
}

void Game::clipPlayer(void)
{
    while (player.getX() < 5) {
        player.moveRight();
    }
    while (player.getX() > width - 5) {
        player.moveLeft();
    }
    while (player.getY() < 2) {
        player.moveDown();
    }
    while (player.getY() > height - 3) {
        player.moveUp();
    }
}

void Game::shoot(void)
{

    int py = player.getY();
    int px = player.getX();
    if (weaponCooldown < 0) {
        if (player.getWeaponLevel() == 0) {
            bullets[getInactiveBullet()].activate(py, px, 0, 0.5);
        }
        if (player.getWeaponLevel() == 1) {
            bullets[getInactiveBullet()].activate(py + 1, px, 0, 1.2);
            bullets[getInactiveBullet()].activate(py - 1, px, 0, 1.2);
        }
        if (player.getWeaponLevel() == 2) {
            bullets[getInactiveBullet()].activate(py, px, 0, 1.4);
            bullets[getInactiveBullet()].activate(py + 1, px, 0.05, 1.3);
            bullets[getInactiveBullet()].activate(py, px, -0.05, 1.3);
        }
        if (player.getWeaponLevel() == 3) {
            bullets[getInactiveBullet()].activate(py + 1, px, 0, 1.5);
            bullets[getInactiveBullet()].activate(py + 2, px, 0.1, 1.4);
            bullets[getInactiveBullet()].activate(py - 1, px, 0, 1.5);
            bullets[getInactiveBullet()].activate(py - 1, px, -0.1, 1.4);
        }
        if (player.getWeaponLevel() == 4) {
            bullets[getInactiveBullet()].activate(py + 1, px, 0, 1.6);
            bullets[getInactiveBullet()].activate(py - 1, px, 0, 1.6);
            bullets[getInactiveBullet()].activate(py + 1, px + 2, 0, 1.7);
            bullets[getInactiveBullet()].activate(py - 1, px + 2, 0, 1.7);
            bullets[getInactiveBullet()].activate(py + 2, px, 0.1, 1.6);
            bullets[getInactiveBullet()].activate(py - 1, px, -0.1, 1.6);
        }
        if (player.getWeaponLevel() == 5) {
            bullets[getInactiveBullet()].activate(py + 1, px, 0, 1.6);
            bullets[getInactiveBullet()].activate(py - 1, px, 0, 1.6);
            bullets[getInactiveBullet()].activate(py + 1, px + 2, 0, 1.7);
            bullets[getInactiveBullet()].activate(py - 1, px + 2, 0, 1.7);
            bullets[getInactiveBullet()].activate(py + 2, px, 0.1, 1.2);
            bullets[getInactiveBullet()].activate(py - 1, px, -0.1, 1.2);
            bullets[getInactiveBullet()].activate(py + 2, px, 0.25, 1.3);
            bullets[getInactiveBullet()].activate(py - 1, px, -0.25, 1.3);
            bullets[getInactiveBullet()].activate(py + 2, px, 0.4, 1.5);
            bullets[getInactiveBullet()].activate(py - 1, px, -0.4, 1.5);
        }
        weaponCooldown = WEAPON_COOLDOWN_TIME;
    }
}

int Game::getInactiveBullet(void)
{
    for (int i = 0; i < BULLET_CLIP; ++i) {
        if (!bullets[i].getActive()) {
            return i;
        }
    }
    return 0;
}

int Game::getInactiveBulletE(void)
{
    for (int i = 0; i < BULLET_CLIP; ++i) {
        if (!enemyBullets[i].getActive()) {
            return i;
        }
    }
    return 0;
}

void Game::updateBullets(void)
{
    weaponCooldown--;
    for (int i = 0; i < BULLET_CLIP; ++i) {
        if (bullets[i].getActive()) {
            bullets[i].update();
            if (bullets[i].getX() < 1 || bullets[i].getX() > width - 1)
                bullets[i].toggleActive();
            if (bullets[i].getY() < 1 || bullets[i].getY() > height - 1)
                bullets[i].toggleActive();
        }
    }
    for (int i = 0; i < BULLET_CLIP; ++i) {
        if (enemyBullets[i].getActive()) {
            enemyBullets[i].update();
            if (enemyBullets[i].getX() < 1 || enemyBullets[i].getX() > width - 1)
                enemyBullets[i].toggleActive();
            if (enemyBullets[i].getY() < 1 || enemyBullets[i].getY() > height - 1)
                enemyBullets[i].toggleActive();
        }
    }
}

void Game::updateEnemies(void)
{
    difficulty++;
    for (int i = 0; i < ENEMIES; ++i) {
        if (!enemies[i].getActive()) {
            if (rand() % 400000 <= (difficulty / 20)) {
                enemies[i].activate(2 + (rand() % (height - 5)), width - 3,
                    0.0, -0.3);
            }
        }
        else {
            if (rand() % 1000 < 1) {
                float yp = enemies[i].getY();
                float xp = enemies[i].getX();
                enemyBullets[getInactiveBulletE()]
                    .activate(yp, xp, 0, -0.4);
            }
            enemies[i].update();
            if (enemies[i].getX() < 1 || enemies[i].getX() > width - 1) {
                if (enemies[i].getX() < 1)
                    difficulty = -100;
                enemies[i].toggleActive();
            }
            if (enemies[i].getY() < 1 || enemies[i].getY() > height - 1)
                enemies[i].toggleActive();
        }
    }
}

void Game::collide(void)
{
    for (int i = 0; i < BULLET_CLIP; ++i) {
        for (int j = 0; j < ENEMIES; ++j) {
            if (enemies[j].getActive() && bullets[i].getActive()) {
                float by = bullets[i].getY();
                float bx = bullets[i].getX();
                float ey = enemies[j].getY();
                float ex = enemies[j].getX();
                if ((bx < ex + 2.0 && bx > ex - 2.0)
                    && (by < ey + 2.0 && by > ey - 2.0)) {
                    enemies[j].toggleActive();
                    bullets[i].toggleActive();
                    score++;
                }
            }
        }
    }
}

int Game::getDifficulty(void)
{
    return difficulty;
}

int Game::getWidth(void)
{
    return width;
}

int Game::getScore(void)
{
    return score;
}

Player& Game::getPlayer(void)
{
    return player;
}

WINDOW* Game::gameWin()
{
    return (this->win);
}

Game::~Game()
{
}

Game::Game(const Game& cc)
{
    score = cc.score;
}
Game& Game::operator=(const Game& cc)
{
    score = cc.score;
    return *this;
}
