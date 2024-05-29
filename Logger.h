#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logFile; // A file to write in

public:
    Logger(const std::string& filename);
    ~Logger();
    Logger& operator<<(const std::string& message);
    Logger& operator<<(int value);
};

#endif // LOGGER_H
