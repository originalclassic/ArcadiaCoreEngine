// Engine/Source/ArcadiaCore/Public/Platform/Platform.h
#pragma once

#ifdef _WIN32
    #include "Windows/WindowsPlatform.h"
#elif defined(__linux__)
    #include "Linux/LinuxPlatform.h"
// Add more platforms as needed here, e.g.:
#elif defined(__APPLE__) && defined(__MACH__)
    #include "Mac/MacPlatform.h"
#elif defined(__ANDROID__)
    #include "Android/AndroidPlatform.h"
// Add more platforms as needed

#else
    #error "Unsupported platform! ACE Engine currently only supports Windows, Linux, Mac, and Android."
#endif

// Define platform-independent macros and utilities here
