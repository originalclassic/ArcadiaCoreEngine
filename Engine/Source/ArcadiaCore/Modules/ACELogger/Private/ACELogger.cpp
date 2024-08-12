#include "ACELogger.h"
#include <iostream>
#include <ctime>

ACELogger::ACELogger() {}

ACELogger::~ACELogger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

ACELogger& ACELogger::GetInstance() {
    static ACELogger instance;
    return instance;
}

void ACELogger::SetLogFile(const std::string& filename) {
    if (logFile.is_open()) {
        logFile.close();
    }
    logFile.open(filename, std::ios::out | std::ios::app);
}

void ACELogger::SetLogLevel(LogLevel level) {
    currentLogLevel = level;
}

void ACELogger::Log(const std::string& message, LogLevel level) {
    if (level < currentLogLevel) {
        return;
    }

    std::string prefix;
    switch (level) {
        case LogLevel::Info: prefix = "[INFO] "; break;
        case LogLevel::Warning: prefix = "[WARNING] "; break;
        case LogLevel::Error: prefix = "[ERROR] "; break;
        case LogLevel::Debug: prefix = "[DEBUG] "; break;
    }

    // Get current time
    std::time_t now = std::time(nullptr);
    char timeStr[100];
    std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::string logEntry = std::string(timeStr) + " " + prefix + message;

    // Output to log file if available
    if (logFile.is_open()) {
        logFile << logEntry << std::endl;
    }

    // Also print to the console
    std::cout << logEntry << std::endl;
}
