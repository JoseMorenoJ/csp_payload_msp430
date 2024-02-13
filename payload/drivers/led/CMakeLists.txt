
add_library(led STATIC
    src/led.c
)

target_include_directories(led
    PUBLIC inc
    PRIVATE src
)

target_link_libraries(led driverlib)
