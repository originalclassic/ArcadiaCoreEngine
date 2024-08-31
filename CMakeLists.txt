cmake_minimum_required(VERSION 3.28)
project(ACE)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories in order
add_subdirectory(Engine/Source/ArcadiaCore/Modules/ACELogger)  # Ensure ACELogger is added early
add_subdirectory(Engine/Source/ArcadiaCore/AModule)
add_subdirectory(Engine/Source/ArcadiaCore/Modules/ACEInput)
add_subdirectory(Engine/Source/ArcadiaCore/Modules/BuildTool)  # BuildTool depends on ACELogger
add_subdirectory(Engine)
add_subdirectory(Game)
add_subdirectory(Engine/Source/ArcadiaCore/Modules/Launch)

# Include directories for the whole project
include_directories(
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/AModule/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACELogger/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACEInput/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/BuildTool/Public  # Corrected path
        ${CMAKE_SOURCE_DIR}/Engine/Config
)

# Define source files for ACE
set(ENGINE_SOURCES
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/UACERenderer.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/UACEEngine.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/EngineConfig.cpp
)

# Add ACE library
add_library(ACE SHARED ${ENGINE_SOURCES})

# Link ACE with AModule and ACELogger
target_link_libraries(ACE PRIVATE AModule ACELogger)
target_link_libraries(GameExecutable PRIVATE Launch)