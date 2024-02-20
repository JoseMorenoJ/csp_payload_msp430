
# Add the executable
set(TARGET ${PROJECT_NAME}.elf)

# Create target
add_executable(${TARGET}
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src/FreeRTOSConfig.c
)

# Absolute path to FreeRTOS config file directory
set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/config/freertos/inc" CACHE STRING "Absolute path to the directory with FreeRTOSConfig.h")

include_directories(${TARGET} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src
    PUBLIC
    ${FREERTOS_CONFIG_FILE_DIRECTORY}
)

add_subdirectory(drivers/msp430fr5xx_6xx)
add_subdirectory(drivers/dbg_print)
add_subdirectory(drivers/led)
add_subdirectory(middleware/freertos)

target_link_libraries(${TARGET} driverlib led dbg_print freertos_kernel)
