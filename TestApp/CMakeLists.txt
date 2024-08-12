cmake_minimum_required(VERSION 3.28)
project(TestApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files for the test application
set(TEST_APP_SOURCES
        main.cpp
)

# Add the executable
add_executable(TestApp ${TEST_APP_SOURCES})

# Link against ACE and AModule libraries
target_link_libraries(TestApp ACE AModule)

# Specify include directories for TestApp
target_include_directories(TestApp PRIVATE
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/AModule/Public
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACEMemoryManager/include
)
