
#include <string>
#include <iostream>
#include "Logger.hpp"

int main()
{
    Logger logfile = Logger("testfile.txt");
    logfile.log("file", "test\n");
    logfile.log("file", "test\n");
    logfile.log("file", "test\n");
    logfile.log("file", "test\n");
    logfile.log("file", "test\n");

    Logger logconsole = Logger();
    logconsole.log("console", "testc\n");
    logconsole.log("console", "testc\n");
    logconsole.log("console", "testc\n");
    logconsole.log("console", "testc\n");
    logconsole.log("console", "testc\n");

    return 0;
}
