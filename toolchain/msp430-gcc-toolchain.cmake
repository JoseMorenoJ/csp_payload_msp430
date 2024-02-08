# CMAKE toolchain for the MSP430FR microcontroller

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR msp430)

# This can To load different assembly code
set(DEVICE "msp430fr5994" CACHE STRING "MSP430 Model")

# MSP430 support files (installation dependent --> ADJUST ACCORDINGLY)
set(PATH_MSP430_SUPPORT "C:/ti/msp430-gcc/include" CACHE STRING "")
set(PATH_MSP430_LIB "C:/ti/msp430-gcc/msp430-elf/lib/large" CACHE STRING "")
set(PATH_MSP430_BIN "C:/ti/msp430-gcc/bin" CACHE STRING "")
set(PATH_MSP430_INCLUDE "C:/ti/msp430-gcc/lib/gcc/msp430-elf/9.3.1/include" CACHE STRING "")


# MSP430 Debug path (installation dependent--> ADJUST ACCORDINGLY)
set(MSPDEBUG "C:/ti/msp430-gdbproxy/msp430-gdbproxy.exe" CACHE STRING "")

# Device specific driverlib
set(PATH_MSP430_DRIVERS "${CMAKE_CURRENT_LIST_DIR}/MSP430FR5xx_6xx" CACHE STRING "")

# default linkerscript
set(LINKER_SCRIPT
    "${DEVICE}.ld"
    CACHE
    FILEPATH "linkerscript"
    )

set(CMAKE_C_COMPILER    "${PATH_MSP430_BIN}/msp430-elf-gcc.exe")
set(CMAKE_CXX_COMPILER  "${PATH_MSP430_BIN}/msp430-elf-g++.exe")
set(CMAKE_AR            "${PATH_MSP430_BIN}/msp430-elf-ar.exe")
set(CMAKE_LINKER        "${PATH_MSP430_BIN}/msp430-elf-ld.exe")
set(CMAKE_NM            "${PATH_MSP430_BIN}/msp430-elf-nm.exe")
set(CMAKE_OBJDUMP       "${PATH_MSP430_BIN}/msp430-elf-objdump.exe")
set(CMAKE_STRIP         "${PATH_MSP430_BIN}/msp430-elf-strip.exe")
set(CMAKE_RANLIB        "${PATH_MSP430_BIN}/msp430-elf-ranlib.exe")
set(CMAKE_SIZE          "${PATH_MSP430_BIN}/msp430-elf-size.exe")

set(CMAKE_FIND_ROOT_PATH  "")

# Compiler flags
set(COMMON_FLAGS "-gdwarf-3 -gstrict-dwarf -I${PATH_MSP430_SUPPORT} -I${PATH_MSP430_LIB} -I${PATH_MSP430_DRIVERS} -I${PATH_MSP430_INCLUDE}" CACHE STRING "")

set(LARGE_DATA_MODEL_FLAGS "-D__LARGE_DATA_MODEL__ -mlarge -mcode-region=lower -mdata-region=lower" CACHE STRING "")
set(MCU_SPECIFIC_CFLAGS "-MMD -mhwmult=f5series -mmcu=${DEVICE} ${LARGE_DATA_MODEL_FLAGS}" CACHE STRING "")

set(CMAKE_C_FLAGS "${MCU_SPECIFIC_CFLAGS} ${COMMON_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "")

# Linker flags
set(MCU_SPECIFIC_LINKER_FLAGS "-L${PATH_MSP430_LIB} -mmcu=${DEVICE} ${LARGE_DATA_MODEL_FLAGS}" CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS "${MCU_SPECIFIC_LINKER_FLAGS} -L${PATH_MSP430_SUPPORT} -T${LINKER_SCRIPT}" CACHE STRING "")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
