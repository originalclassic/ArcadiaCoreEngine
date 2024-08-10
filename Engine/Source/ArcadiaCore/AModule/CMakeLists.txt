cmake_minimum_required(VERSION 3.28)
project(AModule)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and include directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Private)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Public)

# Define source files
set(A_MODULE_SOURCES
        ${SRC_DIR}/JSONParser.cpp
        ${SRC_DIR}/ModuleManager.cpp
        ${SRC_DIR}/INIParser.cpp
)

# Debugging information
message(STATUS "A Module Source files: ${A_MODULE_SOURCES}")

# Create the static library
add_library(AModule STATIC ${A_MODULE_SOURCES})

# Specify include directories
target_include_directories(AModule PUBLIC
        ${INCLUDE_DIR}
)

# Output include directories for debugging
get_target_property(INCLUDE_DIRS AModule INCLUDE_DIRECTORIES)
message(STATUS "AModule include directories: ${INCLUDE_DIRS}")
