cmake_minimum_required(VERSION 3.6)

include(msp430-toolchain.cmake)

project(csp_payload)

message(STATUS "CMAKE_C_COMPILER='${CMAKE_C_COMPILER}'")
message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")

# The default C Flags
list(APPEND BUILD_FLAGS_LIST
    ${CMAKE_C_FLAGS}
    -O0
    -std=c11
    -fno-builtin
    -Wall
    -Wno-int-to-pointer-cast
    -g
    -gdwarf-3
    -gstrict-dwarf
    -fstrict-aliasing
    -Wstrict-aliasing
)

set(CMAKE_C_FLAGS ${BUILD_FLAGS_LIST})


# Compile the source
# But it only makes sense to build one at a time since example_msp430.map will be overwritten
add_subdirectory(payload)
