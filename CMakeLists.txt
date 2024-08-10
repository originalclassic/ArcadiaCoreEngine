cmake_minimum_required(VERSION 3.28)
project(ACE)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Engine)

# Include directories for the whole project
include_directories(
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Public
)

# Explicitly define source files instead of using GLOB_RECURSE
set(ENGINE_SOURCES
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/UACERenderer.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/UACEEngine.cpp
        # Add all other source files here
)

set(GAME_SOURCES
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Private/main.cpp
        # Add all other source files here
)

# Add libraries and executables
add_library(ACE SHARED ${ENGINE_SOURCES})
add_executable(GameProject ${GAME_SOURCES})

# Link libraries
target_link_libraries(GameProject ACE)

# Optionally set additional properties or configurations if needed
