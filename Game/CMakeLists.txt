cmake_minimum_required(VERSION 3.28)
project(GameProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files for the game
set(GAME_SOURCES
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Private/main.cpp
        # Add all other source files here
)

# Add the executable
add_executable(GameProject ${GAME_SOURCES})

# Link against ACE library
target_link_libraries(GameProject ACE)

# Specify include directories
target_include_directories(GameProject PRIVATE
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Public
        ${CMAKE_SOURCE_DIR}/Game/Source/GameProject/Public
)
