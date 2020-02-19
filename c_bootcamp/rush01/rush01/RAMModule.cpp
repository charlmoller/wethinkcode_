
#include "RAMModule.hpp"

void RAMModule::update(Monitor& env) {

    FILE *f = popen("vm_stat", "r");

    char output[200];

    this->setData(std::string(output));
}
