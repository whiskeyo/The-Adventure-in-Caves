cmake_minimum_required(VERSION 3.20)
project(the-adventure-in-caves)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Wpedantic") # add -Werror after fixing compilation errors
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(assets)
