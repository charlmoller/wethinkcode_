
#include "OSInfoModule.hpp"

void OSInfoModule::update(Monitor& env) {

    struct utsname unameData;
    uname(&unameData);
    char output[500];
    sprintf(output, "%s, %s, %s, %s",
        unameData.sysname,
        unameData.release,
        unameData.machine,
        unameData.version
    );
    this->setData(std::string(output));
    
}
