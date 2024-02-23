# Define the executable
set(target dbg_print)

# Create the target
add_library(${target} STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/dbg_print.c
)

target_include_directories(${target}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(${target} driverlib)
