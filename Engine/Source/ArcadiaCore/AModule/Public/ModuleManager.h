#pragma once

#include <string>

class ModuleManager {
public:
    void LoadModule(const std::string& modulePath);

private:
    void AddIncludeDirectory(const std::string& dir);
    void AddSourceFile(const std::string& file);
};
