
//#include <mach/mach.h>
//#include <mach/mach_error.h>
#include "CPUModule.hpp"

void CPUModule::update(Monitor& env) {

    char output[500];

    natural_t cpuCount;
    processor_info_array_t infoArray;
    mach_msg_type_number_t infoCount;
    kern_return_t kr;
    processor_cpu_load_info_data_t* cpuLoadInfo;
    unsigned long old_ticks,new_ticks,old_totalTicks,new_totalTicks;
    int cpu,state;
    old_ticks = 0;
    old_totalTicks = 0;

    kr = host_processor_info(mach_host_self(),
            PROCESSOR_CPU_LOAD_INFO, &cpuCount, &infoArray, &infoCount);
    if (kr) {
        mach_error("host_processor_info error:", kr);
        return kr;
    }

    cpuLoadInfo = (processor_cpu_load_info_data_t*) infoArray;

    new_ticks = new_totalTicks = 0;
    for (cpu = 0; cpu<cpuCount; cpu++){
        for (state = 0; state<CPU_STATE_MAX; state++) {
            if(state != 2)
                new_ticks += cpuLoadInfo[cpu].cpu_ticks[state];
            new_totalTicks += cpuLoadInfo[cpu].cpu_ticks[state];
        }
    }

    sprintf(output, "%2.0lf\n",(double)(new_ticks - old_ticks)/(new_totalTicks - old_totalTicks)*100);

    vm_deallocate(mach_task_self(), (vm_address_t)infoArray, infoCount);

    this->setData(std::string(output));
}
