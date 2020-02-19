
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <map>
#include "Logger.hpp"

typedef void (Logger::*LogType)(std::string);

std::string Logger::makeLogEntry(std::string msg) {
    time_t curr_time;
    tm * curr_tm;
    char date_str[100];
    
    time(&curr_time);
    curr_tm = localtime(&curr_time);
    
    strftime(date_str, 50, "%B-%d-%Y-%T : ", curr_tm);
    return std::string(date_str) + msg;
}

void Logger::logToConsole(std::string msg) {
    std::cout << msg;
}

void Logger::logToFile(std::string msg) {
    std::ofstream output( this->file.c_str(), std::ofstream::app );
    output << msg;
    output.close();
}

void Logger::log(std::string const & dest, std::string const & message) {
    /* Apparently we can't use map yet, but here it is
    // create map of function pointers
    std::map<std::string, LogType> actions;
    
    // assign references to member function
    actions["console"] = &Logger::logToConsole;
    actions["file"] = &Logger::logToFile;

    // check whether key exists to prevent segfault
    if (actions.count(dest)) {
        LogType selected = actions[dest];
        // dereference pointer and call non-static member function
        (this->*selected)(message);
    }
    */
    std::string actions_str[2] = {
        "console",
        "file"
    };

    LogType actions[2] = {
        &Logger::logToConsole,
        &Logger::logToFile
    };

    for (int i = 0; i < 2; ++i)
    {
        if ( actions_str[i] == dest ) {
            LogType selected = actions[i];
            (this->*selected)(message);    
        }
    }
}

Logger::Logger(std::string f) : file(f) {}
//    std::ofstream* temp = new std::ofstream(file);
//    ofile = temp;
//}

Logger::Logger() {}

Logger::~Logger() {}
