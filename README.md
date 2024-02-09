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

## Limitations and bugs

### GCC build

- Large data model is used for the blink example but not with FreeRTOS.
- FreeRTOS is not running properly. Some issues when changing the context. I suspect is related to the data model.

### CCS build

- CMake fails to build the minimum example program. Some issues with the linker.

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
