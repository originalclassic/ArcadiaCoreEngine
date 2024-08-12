#include "UACEEngine.h"
#include "ACELogger.h"

UACEEngine::UACEEngine()
    : ACE_bIsRunning(false) {
    // Log the initialization of the engine
    ACELogger::GetInstance().Log("UACEEngine initialized", LogLevel::Debug);
}

UACEEngine::~UACEEngine() {
    ACE_ShutdownEngine();
}

void UACEEngine::ACE_InitializeEngine() {
    ACE_bIsRunning = true;
    // Initialization code here
    ACELogger::GetInstance().Log("Engine started", LogLevel::Debug);
}

void UACEEngine::ACE_ShutdownEngine() {
    if (ACE_bIsRunning) {
        ACE_bIsRunning = false;
        // Cleanup code here
        ACELogger::GetInstance().Log("Engine shut down", LogLevel::Debug);
    }
}
