cmake_minimum_required(VERSION 3.6)

# Include the toolchain to be used and set the "COMPILER_FAMILY" variable used (GCC or CCS)
include(toolchain/msp430-ccs-toolchain.cmake)

project(csp_payload C ASM)

message(STATUS "CMAKE_C_COMPILER='${CMAKE_C_COMPILER}'")

# Heap number or absolute path to custom heap implementation provided by user
set(FREERTOS_HEAP "4" CACHE STRING "FreeRTOS heap model number. 1 .. 5. Or absolute path to custom heap source file")
set(FREERTOS_PORT "CCS_MSP430X" CACHE STRING "FreeRTOS port name")

# libcsp uses CMAKE_SYSYTEM_NAME to build the arch dependent sources
set(CMAKE_SYSTEM_NAME FreeRTOS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_compile_options(
    # --advice:power=all
    # --advice:hw_config=all
    --silicon_version=mspx
    --use_hw_mpy=F5
    --data_model=large
    --code_model=large
    --printf_support=minimal
    --diag_warning=225
    --diag_wrap=off
    --display_error_number
    --emit_warnings_as_errors
    --c11
    -o2
    -g
)

# The linker options for CCS
add_link_options(
    --xml_link_info=payload/${PROJECT_NAME}_link_info.xml
    --map_file=payload/${PROJECT_NAME}.map
    --heap_size=160
    --stack_size=160
    --cinit_hold_wdt=on
    --priority
    --reread_libs
    --warn_sections
    --diag_wrap=off
    --use_hw_mpy=F5
    --rom_model
)

# Compile the source (the binaries will be generated in build/payload)
add_subdirectory(payload)
