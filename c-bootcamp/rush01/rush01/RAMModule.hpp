
#ifndef RAM_MODULE_HPP
#define RAM_MODULE_HPP

#include "Monitor.hpp"

class RAMModule : public IMonitorModule
{
public:
    virtual void update(Monitor& env);
};

#endif // RAM_MODULE_HPP
