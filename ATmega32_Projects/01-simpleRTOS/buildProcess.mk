CPU_CLK= 8000000UL
MCU= atmega32
rtosCFile = Include/SERVICES/RTOS/RTOS_Program.c
rtosOFile = Debug/$(subst .c,.o,$(subst Include,build,$(rtosCFile)) )
rtosDFile = Debug/$(subst .c,.d,$(subst Include,build,$(rtosCFile)) )

timer1CFile = Include/MCAL/TIMER1/TIMER1_Program.c
timer1OFile = Debug/$(subst .c,.o,$(subst Include,build,$(timer1CFile)) )
timer1DFile = Debug/$(subst .c,.d,$(subst Include,build,$(timer1CFile)) )

dioCFile = Include/MCAL/DIO/DIO_Program.c
dioOFile = Debug/$(subst .c,.o,$(subst Include,build,$(dioCFile)) )
dioDFile = Debug/$(subst .c,.d,$(subst Include,build,$(dioCFile)) )

mainCFile = main.c
mainOFile = Debug/main.o
mainDFile = Debug/main.d

mapFile = Debug/RTOS_Driver1.map
elfFile = Debug/RTOS_Driver1.elf
lssFile = Debug/RTOS_Driver1.lss
hexFile = Debug/RTOS_Driver1.hex
