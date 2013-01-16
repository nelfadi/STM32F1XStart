target remote localhost:3333
monitor reset halt
monitor stm32f1x mass_erase 0
monitor flash write_image program.elf
monitor reset run
quit