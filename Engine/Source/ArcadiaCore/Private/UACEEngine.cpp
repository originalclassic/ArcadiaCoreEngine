#include "UACEEngine.h"

UACEEngine::UACEEngine()
    : ACE_bIsRunning(false) {}

UACEEngine::~UACEEngine() {
    ACE_ShutdownEngine();
}

void UACEEngine::ACE_InitializeEngine() {
    ACE_bIsRunning = true;
    // Initialization code here
}

void UACEEngine::ACE_ShutdownEngine() {
    if (ACE_bIsRunning) {
        ACE_bIsRunning = false;
        // Cleanup code here
    }
}
