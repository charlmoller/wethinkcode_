
#include "HostModule.hpp"

void HostModule::update(Monitor& env) {

    char hostname[500];
    char username[500];
    gethostname(hostname, 500);
    getlogin_r(username, 500);

    // output to string
    char output[100];
    sprintf(output, "[%s] [%s]", hostname, username);

    this->setData(std::string(output));
}
