# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.14)

# Set the project name
project(HAL-lcd-character)

# Make sure we use the C++17 compiler standard
set(CMAKE_CXX_STANDARD 17)

# Create a static library.
add_library(HAL-lcd-character INTERFACE)

# Add the header files just for the IDE, not the build.
target_sources(HAL-lcd-character INTERFACE CharacterDisplay.hpp)
