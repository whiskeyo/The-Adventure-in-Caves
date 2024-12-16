####################################################################################################
# This function converts any file into C/C++ source code.
# Example:
# - input file: data.dat
# - output file: data.h
# - variable name declared in output file: DATA
# - data length: sizeof(DATA)
# embed_resource("data.dat" "data.h" "DATA")
####################################################################################################
function(embed_resource resource_file_name source_file_name variable_name)
    message("Embedding resource: ${resource_file_name} -> ${source_file_name}")
    if(EXISTS "${source_file_name}")
        if("${source_file_name}" IS_NEWER_THAN "${resource_file_name}")
            return()
        endif()
    endif()

    file(READ "${resource_file_name}" hex_content HEX)

    string(REPEAT "[0-9a-f]" 32 pattern)
    string(REGEX REPLACE "(${pattern})" "\\1\n" content "${hex_content}")
    string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1, " content "${content}")
    string(REGEX REPLACE ", $" "" content "${content}")

    set(array_definition "constexpr std::uint8_t ${variable_name}[] =\n{\n${content}\n};")
    set(source "#pragma once\n#include <cstdint>\n${array_definition}\n")

    file(WRITE "${source_file_name}" "${source}")
endfunction()

file(GLOB_RECURSE level_files "${CMAKE_CURRENT_SOURCE_DIR}/levels/*")
foreach(level_file ${level_files})
    get_filename_component(level_name ${level_file} NAME_WE)
    set(level_variable_name "LEVEL_${level_name}")
    set(level_header_file "${CMAKE_CURRENT_BINARY_DIR}/levels/${level_name}.hpp")
    embed_resource("${level_file}" "${level_header_file}" "${level_variable_name}")
endforeach()

file(GLOB_RECURSE texture_files "${CMAKE_CURRENT_SOURCE_DIR}/textures/*")
foreach(texture_file ${texture_files})
    get_filename_component(texture_name ${texture_file} NAME_WE)
    set(texture_variable_name "TEXTURE_${texture_name}")
    set(texture_header_file "${CMAKE_CURRENT_BINARY_DIR}/textures/${texture_name}.hpp")
    embed_resource("${texture_file}" "${texture_header_file}" "${texture_variable_name}")
endforeach()

file(GLOB_RECURSE font_files "${CMAKE_CURRENT_SOURCE_DIR}/fonts/*")
foreach(font_file ${font_files})
    get_filename_component(font_name ${font_file} NAME_WE)
    set(font_variable_name "FONT_${font_name}")
    set(font_header_file "${CMAKE_CURRENT_BINARY_DIR}/fonts/${font_name}.hpp")
    embed_resource("${font_file}" "${font_header_file}" "${font_variable_name}")
endforeach()

include_directories(${CMAKE_CURRENT_BINARY_DIR})
