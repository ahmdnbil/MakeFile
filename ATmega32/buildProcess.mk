CPU_CLK= 8000000UL
DEVICE= atmega32
CC= avr-gcc

rtosCFile = Include/SERVICES/RTOS/RTOS_Program.c
rtosOFile = Debug/$(subst .c,.o,$(rtosCFile))
rtosDFile = Debug/$(subst .c,.d,$(rtosCFile))

timer1CFile = Include/MCAL/TIMER1/TIMER1_Program.c
timer1OFile = Debug/$(subst .c,.o,$(timer1CFile))
timer1DFile = Debug/$(subst .c,.d,$(timer1CFile))

dioCFile = Include/MCAL/DIO/DIO_Program.c
dioOFile = Debug/$(subst .c,.o,$(dioCFile))
dioDFile = Debug/$(subst .c,.d,$(dioCFile))

mainCFile = main.c
mainOFile = Debug/main.o
mainDFile = Debug/main.d

# This variable is for making the layered architecture but for object files
PATHS := $(shell find . -name '*.c' | sed 's|^\./|Debug/|' | xargs -I {} dirname {})
# first thing, find command will get all paths of c files

# second thing, sed command will take find output as input and remove '.' at begining of path and add Debug
# for example ./Include/MCAL/DIO/DIO_Program.c ==> Debug/Include/MCAL/DIO/DIO_Program.c

# third thing, xargs will take output of sed as input and get the directory name of fil using dirname
# for example: Debug/Include/MCAL/DIO/DIO_Program.c ==> Debug/Include/MCAL/DIO/

#to make the name of output files as the name of current directroy [Project name]
currentFolder := $(shell basename $(CURDIR))
mapFile=Debug/$(currentFolder).map
elfFile=Debug/$(currentFolder).elf
lssFile=Debug/$(currentFolder).lss
hexFile=Debug/$(currentFolder).hex
