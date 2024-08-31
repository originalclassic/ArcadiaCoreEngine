#pragma once

#include <string>

class InputHandler {
public:
    // Initialize the input handler
    void Initialize();

    // Process input events
    void ProcessInput();

    // Set the input configuration file
    void SetConfigFile(const std::string& filename);

private:
    std::string configFile;
};
