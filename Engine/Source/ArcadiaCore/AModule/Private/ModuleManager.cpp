#include "ModuleManager.h"
#include "JSONParser.h"
#include <iostream>

#include "../../Modules/ACELogger/Public/ACELogger.h"

void ModuleManager::LoadModule(const std::string& modulePath) {
    JSONParser parser;
    if (!parser.parse(modulePath)) {
        ACELogger::GetInstance().Log("Failed to parse module file: " + modulePath, LogLevel::Error);
        return;
    }
    std::string moduleName = parser.getString("name");
    std::string description = parser.getString("description");
    std::string version = parser.getString("version");

    ACELogger::GetInstance().Log("Loading module: " + moduleName, LogLevel::Info);
    ACELogger::GetInstance().Log("Description: " + description, LogLevel::Info);
    ACELogger::GetInstance().Log("Version: " + version, LogLevel::Info);

    // Load public include directories
    auto includeDirs = parser.getArray("include_directories");
    for (const auto& dir : includeDirs) {
        AddIncludeDirectory(dir);
    }

    // Add source files
    auto sourceFiles = parser.getArray("source_files");
    for (const auto& file : sourceFiles) {
        AddSourceFile(file);
    }

    // Handle dependencies
    auto dependencies = parser.getDependencies();
    for (const auto& dep : dependencies) {
        LoadModule(dep);  // Recursively load dependencies
    }
}

void ModuleManager::AddIncludeDirectory(const std::string& dir) {
    // Implementation to add include directory
    ACELogger::GetInstance().Log("Adding include directory: " + dir, LogLevel::Debug);
}

void ModuleManager::AddSourceFile(const std::string& file) {
    // Implementation to add source file
    ACELogger::GetInstance().Log("Adding source file: " + file, LogLevel::Debug);
}
