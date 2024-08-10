#include "ModuleManager.h"
#include "JSONParser.h"
#include <iostream>

void ModuleManager::LoadModule(const std::string& modulePath) {
    JSONParser parser;
    if (!parser.parse(modulePath)) {
        std::cerr << "Failed to parse module file: " << modulePath << std::endl;
        return;
    }

    std::string moduleName = parser.getString("name");
    std::string description = parser.getString("description");
    std::string version = parser.getString("version");

    std::cout << "Loading module: " << moduleName << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Version: " << version << std::endl;

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
    std::cout << "Adding include directory: " << dir << std::endl;
}

void ModuleManager::AddSourceFile(const std::string& file) {
    // Implementation to add source file
    std::cout << "Adding source file: " << file << std::endl;
}
