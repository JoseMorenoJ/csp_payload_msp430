# CMAKE toolchain for the MSP430FR microcontroller

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR msp430)

# This can To load different assembly code
set(DEVICE "msp430fr5994" CACHE STRING "MSP430 Model")
string(TOUPPER ${DEVICE} DEVICE_DEFINE)
set(DEVICE_DEFINE "__${DEVICE_DEFINE}__")

# The cmake test program compilation uses:
#   ${CMAKE_C_COMPILER} ${CMAKE_C_FLAGS} --run-linker --output_file=xxx --map_file=xxx.map ${CMAKE_EXE_LINKER_FLAGS} xxx.obj
# MSP430 support files (installation dependent --> ADJUST ACCORDINGLY)
set(PATH_TI_CGT_MSP430 "C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS" CACHE STRING "")
set(PATH_MSP430_SUPPORT_INC "C:/ti/ccs1250/ccs/ccs_base/msp430/include" CACHE STRING "")
set(PATH_MSP430_SUPPORT_LIB "C:/ti/ccs1250/ccs/ccs_base/msp430/lib" CACHE STRING "")
set(PATH_MSP430_INCLUDE "${PATH_TI_CGT_MSP430}/include" CACHE STRING "")
set(PATH_MSP430_LIB "${PATH_TI_CGT_MSP430}/lib" CACHE STRING "")
set(PATH_MSP430_BIN "${PATH_TI_CGT_MSP430}/bin" CACHE STRING "")

# Default linker script
set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/${DEVICE}.ld" CACHE FILEPATH "linkerscript")
# Default cmd script
set(CMD_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/lnk_${DEVICE}.cmd" CACHE FILEPATH "cmd linkerscript")

set(CMAKE_C_COMPILER    "${PATH_MSP430_BIN}/cl430.exe")
set(CMAKE_CXX_COMPILER  "${PATH_MSP430_BIN}/cl430.exe")
set(CMAKE_AR            "${PATH_MSP430_BIN}/ar430.exe")
set(CMAKE_C_LINKER      "${PATH_MSP430_BIN}/lnk430.exe")
set(CMAKE_NM            "${PATH_MSP430_BIN}/nm430.exe")
set(CMAKE_OBJDUMP       "${PATH_MSP430_BIN}/ofd430.exe")
set(CMAKE_STRIP         "${PATH_MSP430_BIN}/strip430.exe")
set(MSP430_HEX_TOOL     "${PATH_MSP430_BIN}/hex430.exe")

set(CMAKE_FIND_ROOT_PATH  "")

# Common compile flags
set(CMAKE_C_FLAGS
    "--silicon_errata=CPU21 \
    --silicon_errata=CPU22 \
    --silicon_errata=CPU40 \
    --define=${DEVICE_DEFINE} \
    -I${PATH_MSP430_SUPPORT_INC} \
    -I${PATH_MSP430_INCLUDE}"
    CACHE STRING "")

set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} CACHE STRING "")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS
    "${CMD_LINKER_SCRIPT} \
    -I${PATH_MSP430_SUPPORT_INC} \
    -I${PATH_MSP430_LIB} \
    -I${PATH_MSP430_INCLUDE} \
    -I${PATH_MSP430_SUPPORT_LIB}/5xx_6xx_FRxx \
    -I${PATH_MSP430_SUPPORT_LIB}/FR59xx"
    CACHE STRING "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
