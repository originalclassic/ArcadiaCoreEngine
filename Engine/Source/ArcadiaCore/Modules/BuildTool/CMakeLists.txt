cmake_minimum_required(VERSION 3.10)
project(BuildTool)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add source files
set(SOURCES
        Private/BuildTool.cpp
        Private/BuildFileParser.cpp
        main.cpp
)

# Create the executable
add_executable(BuildTool ${SOURCES})
