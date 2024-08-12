cmake_minimum_required(VERSION 3.28)
project(ACEInput)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and include directories
set(PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Public)
set(PRIVATE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Private)

# Define source files
set(ACEINPUT_SOURCES
        ${PRIVATE_SRC_DIR}/InputHandler.cpp
)

# Create the static library
add_library(ACEInput STATIC ${ACEINPUT_SOURCES})

# Specify include directories
target_include_directories(ACEInput PUBLIC
        ${PUBLIC_INCLUDE_DIR}
)
