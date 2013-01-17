#STM32Start


Simple starting project for the STM32F1xxx MCUs (tested with the STM32F107VCT6 on the Olimex STM32-H107 Board)

##Usage


The Makefile is heavily commented.

TCHAIN_PREFIX contains the complete link to the toolchain, including the complete prefix of the tool names (in my case arm-none-linux-gnueabi-; so the gcc I use for compiling is arm-none-linux-gnueabi-gcc).

SRC contains all source files; if additional C files are needed, these must be put here.

Line 122, the define for the controller family is set (required by the ST StandardLib).

+ STM32F10X_CL = connectivity Line
+ STM32F10X_LD_VL = low-density value line
+ STM32F10X_MD_VL = medium-density value line
+ STM32F10X_HD_VL = high-density value line

Line 128 defines the core clock frequency; the following values are available:

+ SYSCLK_FREQ_HSE
+ SYSCLK_FREQ_24MHz
+ SYSCLK_FREQ_36MHz
+ SYSCLK_FREQ_48MHz
+ SYSCLK_FREQ_56MHz
+ SYSCLK_FREQ_72MHz


##Make targets

make all -> generates program.elf in the main directory; all other build/intermediate files are placed in the directory /out.

make clean -> clean up


##Flashing

stm32.sh -> starts the OpenOCD Daemon
flash.sh -> program the file program.elf into the controller


