cmake_minimum_required(VERSION 3.10)
project(BuildTool)

set(CMAKE_CXX_STANDARD 17)

# Add the source files specific to BuildTool
add_executable(BuildTool
        Private/BuildTool.cpp
        Private/BuildFileParser.cpp
)

# Include directories (e.g., include ACELogger headers)
target_include_directories(BuildTool PRIVATE
        ${CMAKE_SOURCE_DIR}/Engine/Source/ArcadiaCore/Modules/ACELogger/Public
)

# Link against the ACELogger library
target_link_libraries(BuildTool PRIVATE ACELogger)
