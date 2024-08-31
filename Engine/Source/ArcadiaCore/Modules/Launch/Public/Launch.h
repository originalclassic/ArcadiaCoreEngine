// Launch.h
#pragma once

#include <string>

class Launch {
public:
    static Launch& GetInstance();

    // Initialize and run the engine
    void Initialize(int argc, char* argv[]);
    void Shutdown();

private:
    Launch() = default;
    ~Launch() = default;

    // Helper methods for initialization steps
    void InitializeLogger();
    void ParseCommandLine(int argc, char* argv[]);
    void StartGame();
    void StartEditor();

    // Prevent copying
    Launch(const Launch&) = delete;
    Launch& operator=(const Launch&) = delete;
};
