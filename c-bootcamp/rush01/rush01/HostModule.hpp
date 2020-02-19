
#ifndef HOST_MODULE_HPP
#define HOST_MODULE_HPP

#include "Monitor.hpp"

class HostModule : public IMonitorModule
{
public:
    virtual void update(Monitor& env);
};

#endif // HOST_MODULE_HPP
