set(ELF_FILE ${PROJECT_NAME}.elf)

# Absolute path to FreeRTOS config file directory
set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/config/freertos/inc" CACHE STRING "Absolute path to the directory with FreeRTOSConfig.h")
# Heap number or absolute path to custom heap implementation provided by user
set(FREERTOS_HEAP "4" CACHE STRING "FreeRTOS heap model number. 1 .. 5. Or absolute path to custom heap source file")
set(FREERTOS_PORT "CCS_MSP430X" CACHE STRING "FreeRTOS port name")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm -Wl,-Map,\"${EXECUTABLE}.map\"")

add_executable(${ELF_FILE}
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src/FreeRTOSConfig.c
)

include_directories(${ELF_FILE} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/inc
)

add_subdirectory(drivers/msp430fr5xx_6xx)
add_subdirectory(drivers/dbg_print)
add_subdirectory(drivers/led)
add_subdirectory(middleware/freertos)

target_link_libraries(${ELF_FILE} led dbg_print driverlib freertos_kernel)
