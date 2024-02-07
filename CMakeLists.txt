cmake_minimum_required(VERSION 3.6)

include(toolchain/msp430-gcc-toolchain.cmake)

project(csp_payload)

message(STATUS "CMAKE_C_COMPILER='${CMAKE_C_COMPILER}'")
message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")

# The default C Flags
list(APPEND BUILD_FLAGS_LIST
    ${CMAKE_C_FLAGS}
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

# Optimizations depending on debug or release
if(DEFINED DEBUG)
    list(APPEND BUILD_FLAGS_LIST -Og)
else()
    list(APPEND BUILD_FLAGS_LIST -Os)
endif()

set(CMAKE_C_FLAGS ${BUILD_FLAGS_LIST})

# Compile the source
add_subdirectory(payload)
