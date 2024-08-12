cmake_minimum_required(VERSION 3.28)
project(ACE)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(Game)
add_subdirectory(Engine/Source/ArcadiaCore/AModule)  # Ensure this is the correct path
add_subdirectory(Engine/Source/ArcadiaCore/Modules/ACELogger)  # Add this line for ACELogger
add_subdirectory(Engine/Source/ArcadiaCore/Modules/ACEInput)

# Include directories for the whole project
include_directories(
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/AModule/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACELogger/Public  # Updated path for ACELogger
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACEInput/Public
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
target_link_libraries(ACE PRIVATE AModule ACELogger)  # Link ACELogger here
