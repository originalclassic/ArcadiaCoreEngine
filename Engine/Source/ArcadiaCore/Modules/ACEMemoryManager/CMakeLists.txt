cmake_minimum_required(VERSION 3.28)
project(ACEMemoryManager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and include directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define source files
set(MEMORY_MANAGER_SOURCES
        ${SRC_DIR}/FACEAllocator.cpp
        ${SRC_DIR}/FACEFreeListAllocator.cpp
        ${SRC_DIR}/FACEPoolAllocator.cpp
        ${SRC_DIR}/FACEStackAllocator.cpp
        # Add all your source files here
)

# Debugging information
message(STATUS "Memory Manager Source files: ${MEMORY_MANAGER_SOURCES}")

# Create the static library
add_library(ACEMemoryManager STATIC ${MEMORY_MANAGER_SOURCES})

# Specify include directories
target_include_directories(ACEMemoryManager PUBLIC
        ${INCLUDE_DIR}
)
