
#ifndef CPU_MODULE_HPP
#define CPU_MODULE_HPP

#include "Monitor.hpp"

class CPUModule : public IMonitorModule
{
public:
    virtual void update(Monitor& env);
};

#endif // CPU_MODULE_HPP
