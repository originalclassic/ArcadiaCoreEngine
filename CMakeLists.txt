cmake_minimum_required(VERSION 3.28)
project(ACE)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Public
)

# Engine source files
file(GLOB_RECURSE ENGINE_SOURCES
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/*.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public/*.h
)

# Game source files
file(GLOB_RECURSE GAME_SOURCES
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Private/*.cpp
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Public/*.h
)

# Add libraries
add_library(ACE SHARED ${ENGINE_SOURCES})
add_executable(GameProject ${GAME_SOURCES})

# Link libraries
target_link_libraries(GameProject ACE)
