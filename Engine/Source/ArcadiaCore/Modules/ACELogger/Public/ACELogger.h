#pragma once
#include <string>
#include <fstream>
#include <memory>

enum class LogLevel {
    Info,
    Warning,
    Error,
    Debug
};

class ACELogger {
public:
    static ACELogger& GetInstance();

    void Log(const std::string& message, LogLevel level = LogLevel::Info);
    void SetLogFile(const std::string& filename);
    void SetLogLevel(LogLevel level);

private:
    ACELogger();  // Constructor is private to enforce singleton pattern
    ~ACELogger();

    std::ofstream logFile;
    LogLevel currentLogLevel = LogLevel::Info;
};
