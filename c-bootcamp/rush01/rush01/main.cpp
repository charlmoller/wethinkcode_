
#include <ncurses.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cmath>
#include <string>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <locale.h>

#include "Monitor.hpp"
#include "TimeModule.hpp"
#include "HostModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"

long currentTimeMicro()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(int argc, char *argv[])
{
    srand(currentTimeMicro());

    Monitor env = Monitor();
    env.setWidth(240);
    env.setHeight(320);

    IMonitorModule* modules[] = {
        new TimeModule(),
        new HostModule(),
        new OSInfoModule(),
        new CPUModule(),
        new RAMModule(),
        new NetworkModule(),
        NULL
    };

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    curs_set(FALSE);
    cbreak();


    long now = currentTimeMicro();
    while (1) {
        if (now - currentTimeMicro() < -200000) {
            now = currentTimeMicro();


            for (int i = 0; modules[i] != NULL; ++i) {
                modules[i]->update(env);
                ModuleText::render(*modules[i], env);
            }

            env.setDrawPos(0);
            refresh();
        }
    }
    return 0;
}