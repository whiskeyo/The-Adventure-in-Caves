cmake_minimum_required(VERSION 3.20)
project(the-adventure-in-caves)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Wpedantic") # add -Werror after fixing compilation errors

file(GLOB SOURCE_FILES *.cpp)
add_executable(the-adventure-in-caves ${SOURCE_FILES})
target_link_libraries(the-adventure-in-caves sfml-graphics sfml-window sfml-system)
