cmake_minimum_required(VERSION 3.6)

# Include the toolchain to be used and set the "COMPILER_FAMILY" variable used (GCC or CCS)
include(toolchain/msp430-ccs-toolchain.cmake)

project(csp_payload)

message(STATUS "CMAKE_C_COMPILER='${CMAKE_C_COMPILER}'")

message(STATUS "CMAKE_C_COMPILER='${CMAKE_C_COMPILER}'")
message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")

# The default C Flags for CCS
string(APPEND CMAKE_C_FLAGS
    "--emit_warnings_as_errors \
    --c99 \
    --advice:power=all \
    --advice:hw_config=all \
    --printf_support=minimal \
    --diag_warning=225 \
    --diag_wrap=off \
    --display_error_number"
)

# The linker options for CCS
string(APPEND CMAKE_EXE_LINKER_FLAGS
    "-z \
    -m\"${PROJECT_NAME}.map\" \
    --heap_size=160 \
    --stack_size=160 \
    --cinit_hold_wdt=on \
    --priority \
    --reread_libs \
    --diag_wrap=off \
    --display_error_number \
    --warn_sections \
    --xml_link_info=\"${PROJEC_NAME}_link_info.xml\" \
    --use_hw_mpy=F5 \
    --rom_model"
)
# Optimizations depending on debug or release
if(DEFINED DEBUG)
    string(APPEND CMAKE_C_FLAGS " -Og")
    string(APPEND CMAKE_EXE_LINKER_FLAGS " -Og -g")
else()
    string(APPEND CMAKE_C_FLAGS " -O2")
    string(APPEND CMAKE_EXE_LINKER_FLAGS " -O2")
endif()

# Compile the source
add_subdirectory(payload)
