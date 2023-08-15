# *makeFile for ATmega32*

- ###  Flags to create object file

|Flag              | Electivity  | Description |
| :--------------: | :---------: | :-----------|
| ***-mmcu=$(DEVICE)*** | **MUST** | <div><p> DEVICE like atmega32 or any other device from atmel you generate code for </p></div>|
| ***-DF_CPU=$(CPU_CLK)*** | **MUST** | <div><p>CPU_CLK like 8000000UL or any frequency you use </p> </div>|
| ***-c*** | **MUST** | <div> <p>to generate object file and prevent linking stage</p> <p> you must to use this flag if you have more than source file and it's very common in Embedded systems</p> </div> |
| ***-o*** | **MUST** | use it to specifiy the output file to be object file |
| ***-wall***          | **optional**    |<p> Generate warning messages </p>|
| ***-g2***          | **optional**   | <p>Giving more debugging information</p>|
| ***-gstabs***      | **optional**   | <div><p>Giving more debugging information in STABS format</p> <p>See the comparison between -g and -gstabs</p></div> |
| ***-O0 or -Os***   | **recommended**  |<div><p> it sets the level of optimization like -O1 and -O2.</p> <p class="capitalize">If you removde it the defalut is -O0</p> <p class="capitalize">you could benefit from it if you use the inline function</p></div>  |
|***-fpack-struct*** | **optional**| to optimize memeory size by structure packing avoiding padding|
|***-fshort-enums*** | **optional**| avr-gcc will choose the smallest intger type to represent ur enum |
|***-ffunction-sections***|**optional**|place each function into its own individual section in the compiled binary|
|***-fdata-sections***| **optional** |place each global or static variable into its own individual section in the compiled binary|
|***-std=gnu99***| **optional** | it indicates that the code should be compiled using the GNU C99 standard |
| ***-funsigned-char*** | **recommended** | it is used to specify that the char type should be treated as unsigned by default| 
| ***-funsigned-bitfields*** | **optional** |treat bit-fields as unsigned by default|
| ***-MMD*** | **optional** | <div> <p>that generate dependency information for each source file, but will omit system header files</p> <p> This can be useful for tracking the dependencies of your source files</p> </div> |
| ***-MP*** | **optional** | <div> <p>it tells GCC to generate **dependency rules** for each header file that is included in the source file</p> <p>using **-MP** without **-MMD** it might give you error so use them both to avoid errors</p> </div> |
| ***-MF"file.d"*** | **optional** | using -MF it will generate dependency file with the name between double quotes but it by default will generate it with the same name of source file | 
| ***-MT"file.o"*** | **optional** | it's like -MF but it's for object code file to name at as you want |

<br>
<div>
    <div> <b> the following command is full command </b></div> 
    <code>avr-gcc -wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"path/file.d" -MT"path/file.o" -c "path/file.c" -o "path/file.o" </code>
    <div> <b> The minimal command to generate the object file </b> </div>
    <code> avr-gcc -Os -std=gnu99 -mmcu=atmega32 -DF_CPU=8000000UL -c "path/file.c" -o "path/file.o" </code>
</div>
<br>

- ###  Flags to Generate ELF file & linking stage

|Flag              | Electivity  | Description |
| :--------------: | :---------: | :-----------|
| ***-Wl,-Map,$(mapFile)*** | **Optional** | <div> <p> to generate map file which contains info about symbols, sections, libraries, and memroy usage</p> <p> This file can be useful for debugging or optimizing your code. It is not mandatory to generate a map file in the process of generating a hex file</p> </div> |
| ***-mmcu=$(DEVICE)*** | **MUST** | <div><p> Like generating object file</p></div>|
| ***-Ttext=7000*** | **Optional** | <div> <p> Use it to indicate the starting address of flash which reset vector will point to  </p> <p> the defalul address is 0x0000 </p> <p> the 7000, i have mentioned it's for bootlader with size of 2048 word </p> </div> |

<br>
<div>
    <div> <b> the following command is full command </b></div> 
    <code>avr-gcc -Ttext=0000 -Wl,-Map,mapFile.map -mmcu=$(DEVICE) -o elfFile.elf file1.o file2.o file3.o </code>
    <div> <b> The minimal command to generate the object file </b> </div>
    <code> avr-gcc -mmcu=$(DEVICE) -o elfFile.elf file1.o file2.o file3.o</code>
</div>
<br>



- ###  Flags to create LSS file [Optional]
|Flag              | Electivity  | Description |
| :--------------: | :---------: | :-----------|
| ***-h*** | **Optional**| <div> <p> it is used to display the section headers of the object file. Section headers contain information about the name, size, address, and attributes of each section in the file. </p> </div> |
| ***-S*** | **Optional**| <div> <p> it is used to intermix source code with the disassembly of the object file. This means that you can see the original C or assembly code that corresponds to each machine instruction in the file </p> </div> |

<br>
<div>
    <div> <b> the following command is full command </b></div> 
    <code>avr-objdump -h -S elfFile.elf >lssfile.lss </code>
</div>
<br>


- ###  Flags to Generate intel HEX file
|Flag              | Electivity  | Description |
| :--------------: | :---------: | :-----------|
| ***-R*** | **Optional** | to remove the section following this falg like eeprom |
| ***-O*** | **MUST** | to tell the avr-objcopy the output file with the following flag|
| ***ihex*** | **MUST** | to generate output file from the type of Intel Hex file |

<br>
<div>
    <div> <b> the following command is full command </b></div> 
    <code>avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex elfFile.elf hexFile.hex </code>
</div>
<br>