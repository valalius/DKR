// Logger.h

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logFile; // Файл для запису логів

public:
    Logger(const std::string& filename);
    ~Logger();
    Logger& operator<<(const std::string& message);
    Logger& operator<<(int value);
};

#endif // LOGGER_H
