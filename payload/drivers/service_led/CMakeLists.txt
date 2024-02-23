# Define the executable
set(target service_led)

# Create the target
add_library(${target} STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/service_led.c
)

target_include_directories(${target}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(${target} driverlib)
