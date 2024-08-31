// Engine/Source/ArcadiaCore/Public/Logging/Logging.h
#pragma once

#include "../Modules/ACELogger/Public/ACELogger.h"

// Logging macros
#define LOG_INFO(msg) ACELogger::GetInstance().Log(msg, LogLevel::Info)
#define LOG_WARNING(msg) ACELogger::GetInstance().Log(msg, LogLevel::Warning)
#define LOG_ERROR(msg) ACELogger::GetInstance().Log(msg, LogLevel::Error)
#define LOG_DEBUG(msg) ACELogger::GetInstance().Log(msg, LogLevel::Debug)
