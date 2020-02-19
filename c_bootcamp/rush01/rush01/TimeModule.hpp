
#ifndef TIME_MODULE_HPP
#define TIME_MODULE_HPP

#include "Monitor.hpp"

class TimeModule : public IMonitorModule
{
public:
    virtual void update(Monitor& env);
};

#endif // TIME_MODULE_HPP
