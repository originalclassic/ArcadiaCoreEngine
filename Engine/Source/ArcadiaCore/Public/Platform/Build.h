// Engine/Source/ArcadiaCore/Public/Platform/Build.h
#pragma once

// Define build configurations
#if defined(_DEBUG) || defined(DEBUG)
    #define ENGINE_DEBUG 1
#else
    #define ENGINE_DEBUG 0
#endif

// Define any build-related macros
#if defined(_MSC_VER)
    #define ENGINE_COMPILER_MSVC 1
#elif defined(__GNUC__)
    #define ENGINE_COMPILER_GCC 1
#endif

// Define inline macros for specific compilers, if not already defined
#ifndef FORCEINLINE
    #ifdef ENGINE_COMPILER_MSVC
        #define FORCEINLINE __forceinline
    #elif defined(ENGINE_COMPILER_GCC)
        #define FORCEINLINE __attribute__((always_inline)) inline
    #else
        #define FORCEINLINE inline
    #endif
#endif
