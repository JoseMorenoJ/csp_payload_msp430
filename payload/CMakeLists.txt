# Add the executable
set(TARGET ${PROJECT_NAME}.elf)
add_executable(${TARGET})
set_target_properties(${TARGET} PROPERTIES C_STANDARD 11)
set_target_properties(${TARGET} PROPERTIES C_EXTENSIONS ON)

# Absolute path to FreeRTOS config file directory
set(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/config/freertos/inc" CACHE STRING "Absolute path to the directory with FreeRTOSConfig.h")

# Create target
target_sources(${TARGET} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src/FreeRTOSConfig.c
    ${CMAKE_CURRENT_LIST_DIR}/config/system/src/endian.c
)

include_directories(${TARGET}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src
    ${CMAKE_CURRENT_LIST_DIR}/config/system/src
    PUBLIC
    ${FREERTOS_CONFIG_FILE_DIRECTORY}
    ${CMAKE_CURRENT_LIST_DIR}/config/system/inc
)

# Add the drivers subdirectories
add_subdirectory(drivers/msp430fr5xx_6xx)
add_subdirectory(drivers/dbg_print)
add_subdirectory(drivers/service_led)

# Add the middlewares subdirectories
add_subdirectory(middleware/freertos freertos)
add_subdirectory(middleware/libcsp)

# Remove -Wall and -Wextra from libcsp (not compatible options)
get_target_property(EXT_CSP_COMPILE_OPTIONS csp COMPILE_OPTIONS)
list(REMOVE_ITEM EXTLIB_COMPILE_FLAGS -Wall -Wextra)
set_target_properties(csp PROPERTIES COMPILE_OPTIONS "${EXTLIB_COMPILE_FLAGS}" )

# Add the services subdirectories
add_subdirectory(services/service_task service_task)

target_link_libraries(${TARGET} PUBLIC
    driverlib
    dbg_print
    service_led
    freertos_kernel
    service_task
)
