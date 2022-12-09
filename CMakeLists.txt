cmake_minimum_required(VERSION 3.10)
project(TheAdventureInCaves)

# Specify CPP flags and libraries for linking
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Wpedantic")

file(GLOB SOURCE_FILES src/*.cpp)
add_executable(TheAdventureInCaves ${SOURCE_FILES})

target_link_libraries(TheAdventureInCaves sfml-graphics sfml-window sfml-system)
