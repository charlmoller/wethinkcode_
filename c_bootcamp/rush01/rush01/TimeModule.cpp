
#include "TimeModule.hpp"

void TimeModule::update(Monitor& env) {

    // get unix time
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    long unix_time = (currentTime.tv_sec * (int)1e6 + currentTime.tv_usec);

    // local time str
    time_t now = time(0);
    struct tm *time = localtime(&now);
    char local_time[50];
    strftime(local_time, 50, "%Y-%m-%d %H:%M:%S", time);

    // output to string
    char output[50];
    sprintf(output, "[%lu] [%s]", unix_time, local_time);

    this->setData(std::string(output));
}
