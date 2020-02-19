
#ifndef NETWORK_MODULE_HPP
#define NETWORK_MODULE_HPP

#include "Monitor.hpp"

class NetworkModule : public IMonitorModule
{
public:
    virtual void update(Monitor& env);
};

#endif // NETWORK_MODULE_HPP
