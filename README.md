# CMake template msp430fr5994

Examples for MSP430FR5994 LaunchPad based on CMake.

# Build process

1. Install cmake (https://cmake.org/)
1. Download msp430-gcc (https://www.ti.com/tool/MSP430-GCC-OPENSOURCE) and extract in any folder
1. Adjust path to msp430-gcc in msp430-toolchain.cmake accordingly (i.e., replace path of MSP430 support file variables PATH_MSP430_SUPPORT, PATH_MSP430_LIB, PATH_MSP430_BIN, PATH_MSP430_INCLUDE)
1. Create folder *build*
1. Run `cmake -B build -S . -G Ninja` to create build environment
1. Enter the build folder
1. Run `ninja`
1. The binary files are located directly in the build directory and can be flashed to the MSP430 LaunchPad using Uniflash (https://www.ti.com/tool/UNIFLASH?keyMatch=UNIFLASH%20DOWNLOAD).

Once built, it can be imported to a CodeComposer workspace and be debugged.

## My build process

If you need to update the driverlib or if you need to add the driverlib for another device: [www.ti.com/tool/MSPDRIVERLIB](https://www.ti.com/tool/MSPDRIVERLIB)

!!! note
    There is an update for it when using the large data model, it casts an address (20bit) into a `uint16_t` giving a warning. The fix is explained in the [TI forums](https://e2e.ti.com/support/microcontrollers/msp-low-power-microcontrollers-group/msp430/f/msp-low-power-microcontroller-forum/480207/hw_regaccess-h-in-mspware-2-40-00-37-generates-cast-to-pointer-from-integer-of-different-size-warnings-when-compiled-with-gcc_msp430_4-9-14r1_364).

I tried to run the cmake using `include msp430-toolchain.cmake` inside the CMakeListst.txt but it does not import the variables properly.

## Limitations

- Only small data model is used now. If you need the large data model you will need to add some definitions in FreeRTOS.

# Projects

1) *Blinky*: Simple Blinky program
2) *LPM35*: Set device into LPM3.5, wake up using external interrupt
3) *Timer*: Toggle LED periodically using internal timer, test UART
4) *Test*: Test application to investigate power consumption and lifetime using a supercapacitor (UART Baudrate: 9600)
5) *Test_LPM35*: Test application to investigate power consumption and lifetime using a supercapacitor (UART Baudrate: 9600)
6) *Test_Si7021*: Periodically reads and prints temperature/humidity readings from Si7021 sensor
7) *RFM95*: Periodically transmit LoRa packets using RFM95 transceiver

- *Tools*: includes devices drivers, e.g., UART, temperature sensor
- *MSP430FR5xx_6xx*: device drivers from TI to access board's peripherals (e.g., including driverlib)

# MSPDebug

MSPDebug allows to flash and debug boards using command line and gdb.
- To install mspdebug, follow instructions on: https://dlbeer.co.nz/mspdebug (for Windows, checkout: https://dlbeer.co.nz/mspdebug/faq.html#compile_windows and build with `make gcc=CC`)
- Flash program using `mspdebug tilib "prog xxxx.elf"`
- Debug program using GDB with two options:
    1) *Command line:* Start debugging server using  `mspdebug tilib "gdb"`, connect to debug server using `msp430-elf-gdb target remote :2000`, debug using GDB
    2) Start debugging session in VSCode (adjust path of msp430-gdb in *.vscode/launch.json* accordingly)
- Before debugging, flash board with newest firmware!

# Debug with Code Composer

It is easier to use code composer to debug. You can build the project using cmake and ninja and then import the CCS project and debug it.
