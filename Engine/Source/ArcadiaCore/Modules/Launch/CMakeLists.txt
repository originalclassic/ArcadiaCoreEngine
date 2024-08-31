# Launch CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Launch)

set(CMAKE_CXX_STANDARD 17)

# Define source and include directories
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Public)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Private)

# Define source files
set(LAUNCH_SOURCES
        ${SRC_DIR}/Launch.cpp
        ${SRC_DIR}/CommandLine.cpp
)

# Create the static library
add_library(Launch STATIC ${LAUNCH_SOURCES})

# Specify include directories
target_include_directories(Launch PUBLIC
        ${INCLUDE_DIR}
)

# Link with necessary libraries (adjust as needed)
target_link_libraries(Launch ACELogger ACEInput)  # Link with core engine libraries as needed
