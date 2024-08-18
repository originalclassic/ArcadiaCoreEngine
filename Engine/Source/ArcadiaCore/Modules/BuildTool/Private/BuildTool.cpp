#include "../Public/BuildTool.h"
#include "../Public/BuildFileParser.h"
#include "../../ACELogger/Public/ACELogger.h"
#include <iostream>
#include <filesystem> // C++17 feature for directory iteration
#include <cstdlib>    // For system()

namespace fs = std::filesystem;

void BuildTool::Run(int argc, char* argv[]) {
    std::string directoryPath;

    if (argc < 2) {
        directoryPath = fs::current_path().string();
    } else {
        directoryPath = argv[1];
    }

    // Set up logging
    ACELogger& logger = ACELogger::GetInstance();
    logger.SetLogFile("BuildTool.log");  // Set the log file
    logger.Log("Starting the BuildTool...", LogLevel::Info);  // Log the start of the application

    // Check if the directory exists
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        logger.Log("Invalid directory path: " + directoryPath, LogLevel::Error);
        return;
    }

    logger.Log("Scanning directory: " + directoryPath, LogLevel::Info);

    BuildFileParser parser;

    // Iterate through directories and files
    for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
        if (entry.is_directory()) {
            logger.Log("Found subdirectory: " + entry.path().string(), LogLevel::Info);
        }
        if (entry.is_regular_file() && entry.path().extension() == ".Build.cs") {
            logger.Log("Found Build.cs file: " + entry.path().string(), LogLevel::Info);
            parser.Parse(entry.path().string());
        }
    }

    logger.Log("Build process completed.", LogLevel::Info);

    // Compile the build tool and parser (if needed)
    std::system("g++ -c src/BuildTool.cpp -o BuildTool.o");
    std::system("g++ -c src/BuildFileParser.cpp -o BuildFileParser.o");
    std::system("g++ BuildTool.o BuildFileParser.o -o BuildTool");
}
