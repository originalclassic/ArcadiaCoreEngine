cmake_minimum_required(VERSION 3.28)
project(ACEMemoryManager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Memory Manager source files
file(GLOB_RECURSE MEMORY_MANAGER_SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/include/ACEMemoryManager/*.h
)

# Create the static library
add_library(ACEMemoryManager STATIC ${MEMORY_MANAGER_SOURCES})
