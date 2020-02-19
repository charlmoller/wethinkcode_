
#include "Player.hpp"
#include "Game.hpp"
#include "Collider.hpp"

long currentTimeMicro()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int kbhit(void)
{
    int ch, r;

    nodelay(stdscr, TRUE);
    noecho();
    ch = getch();
    if (ch == ERR) {
        r = FALSE;
    }
    else {
        r = TRUE;
        ungetch(ch);
    }
    echo();
    nodelay(stdscr, FALSE);
    return r;
}

int main(void)
{
    setlocale(LC_CTYPE, "");
    srand(currentTimeMicro());

    Game game;

    int wrap = 0;
    long now = currentTimeMicro();
    while (1) {
        if (now - currentTimeMicro() < -20000) {
            now = currentTimeMicro();
            if (kbhit()) {
                int c = getch();
                if (c == KEY_UP)
                    game.getPlayer().up();
                else if (c == KEY_DOWN)
                    game.getPlayer().down();
                else if (c == KEY_RIGHT)
                    game.getPlayer().right();
                else if (c == KEY_LEFT)
                    game.getPlayer().left();
                else if (c == ' ') //spacebar
                    game.shoot();
            }
            game.update();
            if (game.getDifficulty() < 0)
                break;
            wrap++;
            wrap %= game.getWidth();
            game.render(wrap);
        }
    }
    refresh();
    mvprintw(5, 5, "Gave over. Your score: %d", game.getScore());
    refresh();
    sleep(6);
    endwin();
    std::cout << "Gave over. Your score: " << game.getScore() << "\n";
    return 0;
}