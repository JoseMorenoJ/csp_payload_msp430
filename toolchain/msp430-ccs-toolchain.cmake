# CMAKE toolchain for the MSP430FR microcontroller

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR msp430)

# This can To load different assembly code
set(DEVICE "msp430fr5994" CACHE STRING "MSP430 Model")
string(TOUPPER ${DEVICE} DEVICE_DEFINE)
set(DEVICE_DEFINE "__${DEVICE_DEFINE}__")

# MSP430 support files (installation dependent --> ADJUST ACCORDINGLY)
set(PATH_TI_CGT_MSP430 "C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS" CACHE STRING "")
set(PATH_MSP430_SUPPORT "C:/ti/ccs1250/ccs/ccs_base/msp430/include" CACHE STRING "")
set(PATH_MSP430_LIB "${PATH_TI_CGT_MSP430}/lib" CACHE STRING "")
set(PATH_MSP430_BIN "${PATH_TI_CGT_MSP430}/bin" CACHE STRING "")
set(PATH_MSP430_INCLUDE "${PATH_TI_CGT_MSP430}/include" CACHE STRING "")


# Device specific driverlib
set(PATH_MSP430_DRIVERS "${CMAKE_CURRENT_LIST_DIR}/MSP430FR5xx_6xx" CACHE STRING "")

# default linkerscript
set(LINKER_SCRIPT
    "${PATH_MSP430_SUPPORT}/${DEVICE}.ld"
    CACHE
    FILEPATH "linkerscript"
    )

set(CMAKE_C_COMPILER    "${PATH_MSP430_BIN}/cl430.exe")
set(CMAKE_CXX_COMPILER    "${PATH_MSP430_BIN}/cl430.exe")
set(CMAKE_AR            "${PATH_MSP430_BIN}/ar430.exe")
set(CMAKE_LINKER        "${PATH_MSP430_BIN}/lnk430.exe")
set(CMAKE_NM            "${PATH_MSP430_BIN}/nm430.exe")
# set(CMAKE_OBJDUMP       "${PATH_MSP430_BIN}/msp430-elf-objdump.exe")
set(CMAKE_STRIP         "${PATH_MSP430_BIN}/strip430.exe")
# set(CMAKE_RANLIB        "${PATH_MSP430_BIN}/msp430-elf-ranlib.exe")
# set(CMAKE_SIZE          "${PATH_MSP430_BIN}/msp430-elf-size.exe")

set(CMAKE_FIND_ROOT_PATH  "")

# Common compile flags
set(COMMON_FLAGS "\
    --emit_warnings_as_errors \
    --c99 \
    --advice:power=all \
    --advice:hw_config=all \
    --printf_support=minimal \
    --diag_warning=225 \
    --diag_wrap=off \
    --display_error_number \
    -I${PATH_MSP430_SUPPORT} \
    -I${PATH_MSP430_LIB} \
    -I${PATH_MSP430_DRIVERS} \
    -I${PATH_MSP430_INCLUDE}"
)

# MCU specific flags
set(MCU_SPECIFIC_CFLAGS "\
    --silicon_version=mspx \
    --use_hw_mpy=F5 \
    --data_model=restricted \
    --define=${DEVICE_DEFINE} \
    --silicon_errata=CPU21 \
    --silicon_errata=CPU22 \
    --silicon_errata=CPU40"
)

set(CMAKE_C_FLAGS "${MCU_SPECIFIC_CFLAGS} ${COMMON_FLAGS}" CACHE STRING "")

# Linker flags
set(COMMON_LINKER_FLAGS "\
    -L${PATH_MSP430_LIB} \
    -L${PATH_MSP430_SUPPORT} \
    --cinit_hold_wdt=on \
    -Wl,--gc-sections -Wl,-lgcc -Wl,-lc"
)

set(MCU_SPECIFIC_LINKER_FLAGS "
    --silicon_version=mspx \
    -T${LINKER_SCRIPT} \
    --data_model=restricted \
    --use_hw_mpy=F5 \
    --define=__MSP430FR5994__ \
    --silicon_errata=CPU21 \
    --silicon_errata=CPU22 \
    --silicon_errata=CPU40"
)

set(CMAKE_EXE_LINKER_FLAGS "${MCU_SPECIFIC_LINKER_FLAGS} ${COMMON_LINKER_FLAGS}" CACHE STRING "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
