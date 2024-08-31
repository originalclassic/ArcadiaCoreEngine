// Launch.cpp
#include "Launch.h"
#include "../../ACELogger/Public/ACELogger.h"  // Adjust include paths as necessary
#include "CommandLine.h"

Launch& Launch::GetInstance() {
    static Launch instance;
    return instance;
}

void Launch::Initialize(int argc, char* argv[]) {
    InitializeLogger();
    ParseCommandLine(argc, argv);

    // Decide which mode to start based on command-line arguments
    if (CommandLine::Get().HasArgument("editor")) {
        StartEditor();
    } else {
        StartGame();
    }
}

void Launch::InitializeLogger() {
    ACELogger& logger = ACELogger::GetInstance();
    logger.SetLogFile("ACE.log");
    logger.Log("Logger initialized.", LogLevel::Info);
}

void Launch::ParseCommandLine(int argc, char* argv[]) {
    CommandLine::Get().Initialize(argc, argv);
}

void Launch::StartGame() {
    // Placeholder for starting the game
    ACELogger::GetInstance().Log("Starting Game Mode...", LogLevel::Info);
    // Initialize and run game modules
}

void Launch::StartEditor() {
    // Placeholder for starting the editor
    ACELogger::GetInstance().Log("Starting Editor Mode...", LogLevel::Info);
    // Initialize and run editor modules
}

void Launch::Shutdown() {
    // Clean up resources and subsystems
    ACELogger::GetInstance().Log("Shutting down...", LogLevel::Info);
}
