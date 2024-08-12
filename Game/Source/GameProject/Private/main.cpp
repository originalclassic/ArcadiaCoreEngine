#include "UACEEngine.h"
#include "../../../../Engine/Source/ArcadiaCore/Modules/ACELogger/Public/ACELogger.h"


int main() {
    ACELogger::GetInstance().SetLogFile("game_log.txt");
    ACELogger::GetInstance().Log("Game Init", LogLevel::Debug);
    UACEEngine engine;
    engine.ACE_InitializeEngine();

    // Main game loop

    engine.ACE_ShutdownEngine();
    return 0;
}
