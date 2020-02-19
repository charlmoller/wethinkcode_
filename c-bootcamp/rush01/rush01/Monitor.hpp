
#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <ncurses.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <locale.h>
#include <sys/utsname.h>
#include <sys/resource.h>

class Monitor;

class IMonitorModule {
    std::string data;
public:
    virtual void update(Monitor& env) = 0;
    const std::string& getData(void);
    void setData(std::string);
};

class IMonitorDisplay {
public:
    virtual void render(Monitor& env) = 0;
};

class ModuleGui : public IMonitorDisplay
{
public:
    static void render(IMonitorModule& module, Monitor& env);
};

class ModuleText : public IMonitorDisplay
{
public:
    static void render(IMonitorModule& module, Monitor& env);
};

class Monitor {
    int width;
    int height;
    int textMode; // 0 or 1
    int drawPos; // current line/pixel from the top
public:
    void setWidth(int);
    void setHeight(int);
    void setTextMode(int); // 0 or 1
    void setDrawPos(int); // current line/pixel from the top
    int getWidth(void);
    int getHeight(void);
    int getTextMode(void);
    int getDrawPos(void);
};

#endif // MONITOR_HPP
