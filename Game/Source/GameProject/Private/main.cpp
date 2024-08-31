#include "UACEEngine.h"
#include <chrono>
#include <thread>
#include "../../../../Engine/Source/ArcadiaCore/Modules/ACELogger/Public/ACELogger.h"
#include "Core.h"

int main() {
    // Set up logging
    ACELogger::GetInstance().SetLogFile("game_log.txt");
    ACELogger::GetInstance().SetLogLevel(LogLevel::Debug);
    ACELogger::GetInstance().Log("Game Init message", LogLevel::Debug);

    // Initialize the engine
    UACEEngine engine;
    engine.ACE_InitializeEngine();

    // Main game loop
    bool isRunning = true;
    const int targetFPS = 300;
    const int frameDelay = 1000 / targetFPS;

    while (isRunning) {
        auto frameStart = std::chrono::high_resolution_clock::now();

        // 1. Handle Input (placeholder)
        // Example: You can add input handling code here to stop the game when needed
        // if (/* some input condition to exit */) {
        //     isRunning = false;
        // }

        // 2. Update Game Logic (placeholder)
        // You can add game logic updates here, like moving objects, handling collisions, etc.
        // engine.Update();

        // 3. Render (placeholder)
        // Render your game scene here
        // engine.Render();

        // Frame timing control
        auto frameEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> frameDuration = frameEnd - frameStart;
        if (frameDuration.count() < frameDelay) {
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay) - frameDuration);
        }

        // Log each frame (optional)
        ACELogger::GetInstance().Log("Frame rendered", LogLevel::Debug);
    }

    // Shutdown the engine
    engine.ACE_ShutdownEngine();
    ACELogger::GetInstance().Log("Game shutdown complete", LogLevel::Debug);

    return 0;
}
