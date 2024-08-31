#pragma once

class UACEEngine {

public:
    UACEEngine();
    ~UACEEngine();

    void ACE_InitializeEngine();
    void ACE_ShutdownEngine();
private:
    bool ACE_bIsRunning;
};
