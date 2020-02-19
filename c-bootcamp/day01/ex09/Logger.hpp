#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

class Logger
{

private:

    std::string makeLogEntry(std::string);
    void logToConsole(std::string);
    void logToFile(std::string);

public:

    std::string file;

    void log(std::string const & dest, std::string const & message);
    Logger(std::string);
    Logger();
    ~Logger();
    
};


#endif // LOGGER_HPP
