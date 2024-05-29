#include "Logger.h"
#include <iostream>
#include <chrono>
#include <fstream> // to work with files
#include <ctime>   // to work with time

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Error opening log file: " << filename << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

Logger& Logger::operator<<(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    logFile << "[" << std::ctime(&time) << "] " << message << std::endl;
    return *this;
}

Logger& Logger::operator<<(int value) {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    logFile << "[" << std::ctime(&time) << "] " << value << std::endl;
    return *this;
}
