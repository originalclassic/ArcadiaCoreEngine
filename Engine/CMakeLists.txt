cmake_minimum_required(VERSION 3.28)
project(ACEEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Source/ArcadiaCore/AModule)
add_subdirectory(Source/ArcadiaCore/Modules/ACEMemoryManager)

# Define engine source files
set(ENGINE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/Private/UACERenderer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/Private/UACEEngine.cpp
        # Add other engine source files here
)

# Create the main engine library
add_library(ACEEngine STATIC ${ENGINE_SOURCES})

# Link the ACEMemoryManager and AModule libraries to the engine
target_link_libraries(ACEEngine PRIVATE ACEMemoryManager AModule)

# Specify include directories for the engine
target_include_directories(ACEEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/AModule/Public
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/Modules/ACEMemoryManager/Public
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/Public
)
