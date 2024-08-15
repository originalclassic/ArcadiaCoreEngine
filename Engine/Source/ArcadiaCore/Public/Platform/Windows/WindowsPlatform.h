#pragma once

// Include any necessary Windows headers
#include <Windows.h>

// Define any platform-specific macros or utilities here
#define ACE_PLATFORM_WINDOWS 1

// Add any Windows-specific functionality or declarations

class WindowsPlatform {
public:
    static void Initialize() {
        // Initialization code specific to Windows
    }

    static void Shutdown() {
        // Cleanup code specific to Windows
    }
};

