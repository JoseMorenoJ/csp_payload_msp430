# Define the executable
set(target driverlib)

# Create the target
add_library(${target} STATIC
    ${CMAKE_CURRENT_LIST_DIR}/adc12_b.c
    ${CMAKE_CURRENT_LIST_DIR}/aes256.c
    ${CMAKE_CURRENT_LIST_DIR}/comp_e.c
    ${CMAKE_CURRENT_LIST_DIR}/crc.c
    ${CMAKE_CURRENT_LIST_DIR}/crc32.c
    ${CMAKE_CURRENT_LIST_DIR}/cs.c
    ${CMAKE_CURRENT_LIST_DIR}/dma.c
    ${CMAKE_CURRENT_LIST_DIR}/esi.c
    ${CMAKE_CURRENT_LIST_DIR}/eusci_a_spi.c
    ${CMAKE_CURRENT_LIST_DIR}/eusci_a_uart.c
    ${CMAKE_CURRENT_LIST_DIR}/eusci_b_i2c.c
    ${CMAKE_CURRENT_LIST_DIR}/eusci_b_spi.c
    ${CMAKE_CURRENT_LIST_DIR}/framctl.c
    ${CMAKE_CURRENT_LIST_DIR}/framctl_a.c
    ${CMAKE_CURRENT_LIST_DIR}/gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/lcd_c.c
    ${CMAKE_CURRENT_LIST_DIR}/mpu.c
    ${CMAKE_CURRENT_LIST_DIR}/mpy32.c
    ${CMAKE_CURRENT_LIST_DIR}/pmm.c
    ${CMAKE_CURRENT_LIST_DIR}/ram.c
    ${CMAKE_CURRENT_LIST_DIR}/ref_a.c
    ${CMAKE_CURRENT_LIST_DIR}/rtc_b.c
    ${CMAKE_CURRENT_LIST_DIR}/rtc_c.c
    ${CMAKE_CURRENT_LIST_DIR}/sfr.c
    ${CMAKE_CURRENT_LIST_DIR}/sysctl.c
    ${CMAKE_CURRENT_LIST_DIR}/timer_a.c
    ${CMAKE_CURRENT_LIST_DIR}/timer_b.c
    ${CMAKE_CURRENT_LIST_DIR}/tlv.c
    ${CMAKE_CURRENT_LIST_DIR}/wdt_a.c
)

target_include_directories(${target}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
    ${CMAKE_CURRENT_LIST_DIR}
)
