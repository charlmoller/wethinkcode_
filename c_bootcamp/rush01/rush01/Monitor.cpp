
#include "Monitor.hpp"

const std::string& IMonitorModule::getData(void) {
    return this->data;
}

void IMonitorModule::setData(std::string datastr) {
    this->data = datastr;
}

void ModuleGui::render(IMonitorModule& module, Monitor& env) {

}

void ModuleText::render(IMonitorModule& module, Monitor& env) {
    mvprintw(env.getDrawPos(), 1, "%s\n", module.getData().c_str() );
    env.setDrawPos( env.getDrawPos() + 1 );
}

void Monitor::setWidth(int val) {
    width = val;
}

void Monitor::setHeight(int val) {
    height = val;
}

void Monitor::setTextMode(int val) {
    textMode = val;
}

void Monitor::setDrawPos(int val) {
    drawPos = val;
}

int Monitor::getWidth(void) {
    return width;
}

int Monitor::getHeight(void) {
    return height;
}

int Monitor::getTextMode(void) {
    return textMode;
}

int Monitor::getDrawPos(void) {
    return drawPos;
}
