
add_library(led STATIC
    src/led.c
)

target_include_directories(led
    PUBLIC inc
)

target_link_libraries(led driverlib)
