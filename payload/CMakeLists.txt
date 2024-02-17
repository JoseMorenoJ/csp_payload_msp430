
# Add the executable
set(TARGET ${PROJECT_NAME}.elf)

# Create target
add_executable(${TARGET}
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    # ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src/FreeRTOSConfig.c
)

# include_directories(${TARGET} PRIVATE
#     ${CMAKE_CURRENT_LIST_DIR}/config/freertos/src
#     PUBLIC
#     ${CMAKE_CURRENT_LIST_DIR}/config/freertos/inc
# )

# add_subdirectory(drivers/msp430fr5xx_6xx)
# add_subdirectory(drivers/dbg_print)
# add_subdirectory(drivers/led)
# add_subdirectory(middleware/freertos)

# target_link_libraries(${TARGET} driverlib led dbg_print) #freertos_kernel)
