#pragma once

#include <string>
#include <fstream>
#include <memory>
#include "LogLevel.h"  // Include the shared LogLevel enum

class ACELogger {
public:
    static ACELogger& GetInstance();

    void Log(const std::string& message, LogLevel level = LogLevel::Info);
    void LogWithDynamicLevel(const std::string& message, LogLevel dynamicLevel);
    void SetLogFile(const std::string& filename);
    void SetLogLevel(LogLevel level);

private:
    ACELogger();  // Constructor is private to enforce singleton pattern
    ~ACELogger();

    std::ofstream logFile;
    LogLevel currentLogLevel = LogLevel::Info;
};
