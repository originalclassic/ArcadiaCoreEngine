cmake_minimum_required(VERSION 3.28)
project(ACEEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files for the engine
set(ENGINE_SOURCES
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/UACERenderer.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Private/UACEEngine.cpp
        # Add all other source files here
)

# Create the static library
add_library(ACEEngine STATIC ${ENGINE_SOURCES})

# Link against required libraries
target_link_libraries(ACEEngine PRIVATE ACEMemoryManager AModule ACELogger)  # Add ACELogger here

# Specify include directories for the engine
target_include_directories(ACEEngine PUBLIC
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/AModule/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACEMemoryManager/include
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACELogger/Public  # Add ACELogger include directory
)
