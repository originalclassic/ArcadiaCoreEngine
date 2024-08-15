#include "UACEEngine.h"
#include "ACELogger.h"
#include "EngineConfig.h"

UACEEngine::UACEEngine()
    : ACE_bIsRunning(false) {
    // Access the EngineConfig singleton
    EngineConfig& engineConfig = EngineConfig::GetInstance();
    engineConfig.LoadConfig("Engine/Config/Engine.ini");

    // Log the initialization of the engine
    ACELogger::GetInstance().SetLogLevel(engineConfig.GetLogLevel());
    ACELogger::GetInstance().LogWithDynamicLevel("UACEEngine initialized TEST", engineConfig.GetLogLevel());
}

UACEEngine::~UACEEngine() {
    ACE_ShutdownEngine();
}

void UACEEngine::ACE_InitializeEngine() {
    ACE_bIsRunning = true;
    // Initialization code here
    EngineConfig& engineConfig = EngineConfig::GetInstance();
    ACELogger::GetInstance().LogWithDynamicLevel("Engine started", engineConfig.GetLogLevel());
}

void UACEEngine::ACE_ShutdownEngine() {
    if (ACE_bIsRunning) {
        ACE_bIsRunning = false;
        // Cleanup code here
        EngineConfig& engineConfig = EngineConfig::GetInstance();
        ACELogger::GetInstance().LogWithDynamicLevel("Engine shut down", engineConfig.GetLogLevel());
    }
}
