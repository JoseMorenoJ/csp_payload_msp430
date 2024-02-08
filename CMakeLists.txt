cmake_minimum_required(VERSION 3.6)

# Include the toolchain to be used and set the "COMPILER_FAMILY" variable used (GCC or CCS)
include(toolchain/msp430-ccs-toolchain.cmake)

project(csp_payload)

message(STATUS "CMAKE_C_COMPILER='${CMAKE_C_COMPILER}'")
message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")

# The default C Flags for CCS
list(APPEND CCS_BUILD_FLAGS
    "--emit_warnings_as_errors \
    --c99 \
    --advice:power=all \
    --advice:hw_config=all \
    --printf_support=minimal \
    --diag_warning=225 \
    --diag_wrap=off \
    --display_error_number"
)

# The default C Flags for GCC
set(GCC_BUILD_FLAGS
    "-std=c11 \
    -fno-builtin \
    -Wall \
    -Wno-int-to-pointer-cast \
    -g \
    -gdwarf-3 \
    -gstrict-dwarf \
    -fstrict-aliasing \
    -Wstrict-aliasing"
)

# The linker options for CCS
set(CCS_LINKER_FLAGS
    "-g \
    -z \
    --priority \
    --reread_libs \
    --diag_wrap=off \
    --display_error_number \
    --warn_sections \
    --advice:power=all \
    --advice:hw_config=all \
    --printf_support=minimal \
    --diag_warning=225 \
    --rom_model \
    -m\"${PROJECT_NAME}.map\" \
    --heap_size=160 \
    --stack_size=160"
)

# The linker options for GCC
list(APPEND GCC_LINKER_FLAGS
    "-Wl--gc-sections \
    -Wl,-lgcc \
    -Wl,-lc \
    -lm \
    -Wl,-Map,\"${PROJECT_NAME}.map\""
)

# Optimizations depending on debug or release
if(DEFINED DEBUG)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Og -g")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O2")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CCS_BUILD_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${CCS_LINKER_FLAGS}")

# Compile the source
add_subdirectory(payload)
