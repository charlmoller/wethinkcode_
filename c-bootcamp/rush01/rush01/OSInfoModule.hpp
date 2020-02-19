
#ifndef OSINFO_MODULE_HPP
#define OSINFO_MODULE_HPP

#include "Monitor.hpp"

class OSInfoModule : public IMonitorModule
{
public:
    virtual void update(Monitor& env);
};

#endif // OSINFO_MODULE_HPP
