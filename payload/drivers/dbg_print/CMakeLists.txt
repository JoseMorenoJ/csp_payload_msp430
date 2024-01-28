
add_library(dbg_print STATIC
    src/dbg_print.c
)

target_include_directories(dbg_print
    PUBLIC inc
)

target_link_libraries(dbg_print driverlib)
