
# Add the executable
set(TARGET ${PROJECT_NAME}.elf)

# Absolute path to FreeRTOS config file directory
set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/config/freertos/inc" CACHE STRING "Absolute path to the directory with FreeRTOSConfig.h")

# Create target
add_executable(${TARGET}
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src/FreeRTOSConfig.c
)

include_directories(${TARGET}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src
    PUBLIC
    ${FREERTOS_CONFIG_FILE_DIRECTORY}
)

# Add the drivers subdirectories
add_subdirectory(drivers/msp430fr5xx_6xx)
add_subdirectory(drivers/dbg_print)
add_subdirectory(drivers/service_led)

# Add the middlewares subdirectories
add_subdirectory(middleware/freertos freertos)

# Add the services subdirectories
add_subdirectory(services/service_task service_task)

target_link_libraries(${TARGET} PUBLIC
    driverlib
    dbg_print
    service_led
    freertos_kernel
    service_task
)
