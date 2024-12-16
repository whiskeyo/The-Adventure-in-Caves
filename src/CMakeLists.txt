include_directories(${CMAKE_BINARY_DIR}) # for assets

file(GLOB SOURCE_FILES *.cpp)
add_executable(the-adventure-in-caves ${SOURCE_FILES})
target_link_libraries(the-adventure-in-caves sfml-graphics sfml-window sfml-system)
