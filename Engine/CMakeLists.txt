# ACE/Engine/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(ACEEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Source/ArcadiaCore/Modules/ACEMemoryManager)

# Add your engine source files here
set(ENGINE_SOURCES
        # List your source files here
)

# Create the main engine library or executable
add_library(ACEEngine STATIC ${ENGINE_SOURCES})

# Link the ACEMemoryManager library to the engine
target_link_libraries(ACEEngine PRIVATE ACEMemoryManager)

# Optionally, specify include directories for the engine
target_include_directories(ACEEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/Modules/ACEMemoryManager/include
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/include
)

# Optionally, add any other required directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source/ArcadiaCore/include)
