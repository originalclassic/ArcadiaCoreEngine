// Engine/Source/ArcadiaCore/Public/Core.h
#pragma once

#include "EngineConfig.h"

//Include Platform Specific Headers
#include "Platform/Platform.h"

//Include build configurations
#include "Platform/Build.h"

// Include other essential headers
#include "Types.h"      // Define common types
#include "Math/Math.h"  // Basic math functions and classes like Vector, Matrix, etc.
#include "Memory/Memory.h"  // Memory management utilities
#include "Logging/Logging.h"  // Logging utilities


// Declare a global instance of EngineConfig
extern EngineConfig engineConfig;
