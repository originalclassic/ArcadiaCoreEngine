#include "EngineConfig.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Singleton instance
EngineConfig& EngineConfig::GetInstance() {
    static EngineConfig instance;
    return instance;
}

// Constructor
EngineConfig::EngineConfig() : logLevel(LogLevel::Info) {}

// Load configuration from file
bool EngineConfig::LoadConfig(const std::string& filePath) {
    ParseINIFile(filePath);
    return true;
}

// Get ELogDirectory
std::string EngineConfig::GetELogDirectory() const {
    return eLogDirectory;
}

// Get GLogDirectory
std::string EngineConfig::GetGLogDirectory() const {
    return gLogDirectory;
}

// Get LogLevel
LogLevel EngineConfig::GetLogLevel() const {
    return logLevel;
}

// Parse the INI file to set configuration parameters
void EngineConfig::ParseINIFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open INI file: " << filePath << std::endl;
        return;
    }

    std::string line;
    std::string currentSection;
    while (std::getline(file, line)) {
        // Remove leading and trailing whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.empty() || line[0] == ';') {
            continue; // Skip empty lines and comments
        }

        if (line[0] == '[' && line.back() == ']') {
            // Section header
            currentSection = line.substr(1, line.size() - 2);
        } else {
            // Key-value pair
            size_t equalPos = line.find('=');
            if (equalPos != std::string::npos) {
                std::string key = line.substr(0, equalPos);
                std::string value = line.substr(equalPos + 1);

                // Remove leading and trailing whitespace
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                if (currentSection == "Logging") {
                    if (key == "ELogDirectory") {
                        eLogDirectory = value;
                    } else if (key == "GLogDirectory") {
                        gLogDirectory = value;
                    } else if (key == "LogLevel") {
                        if (value == "Info") {
                            logLevel = LogLevel::Info;
                        } else if (value == "Warning") {
                            logLevel = LogLevel::Warning;
                        } else if (value == "Error") {
                            logLevel = LogLevel::Error;
                        } else if (value == "Debug") {
                            logLevel = LogLevel::Debug;
                        }
                    }
                }
            }
        }
    }
}
