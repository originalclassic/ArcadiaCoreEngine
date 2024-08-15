#pragma once


#include "../Modules/ACELogger/Public/LogLevel.h"
#include <string>

class EngineConfig {
public:
    static EngineConfig& GetInstance();

    bool LoadConfig(const std::string& filePath);
    std::string GetELogDirectory() const;
    std::string GetGLogDirectory() const;
    LogLevel GetLogLevel() const;

private:
    EngineConfig();
    ~EngineConfig() = default;

    std::string eLogDirectory;
    std::string gLogDirectory;
    LogLevel logLevel;

    void ParseINIFile(const std::string& filePath);
};
