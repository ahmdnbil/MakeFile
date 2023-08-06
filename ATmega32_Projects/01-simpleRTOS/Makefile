include makeFolders.mk
include buildProcess.mk
	
clean:
	@rm -r Debug

folder:
	@$(foreach word,$(folders),mkdir -p $(word))


#flags
# -wall   [optional ]: Generate warning messages
# -g2     [optional ]: Giving more debugging information
# -gstabs [optional ]: Giving more debugging information in STABS format 
# See the comparison between -g and -gstabs
# -O0 	  [up to you]: it sets the level of optimization like -O1 and -O2
#if you removde it the defalut is -O0
#you could benefit from it if you use the inline function
build: folder 
	@echo "Generate Include files for RTOS"
	@avr-gcc -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=$(MCU) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(rtosDFile)" -MT"$(rtosOFile)" -c -o "$(rtosOFile)" "$(rtosCFile)"
	
	@echo "Generate Include files for TIMER1"
	@avr-gcc -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=$(MCU) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(timer1DFile)" -MT"$(timer1OFile)" -c -o "$(timer1OFile)" "$(timer1CFile)"
	
	@echo "Generate Include files for DIO"
	@avr-gcc -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=$(MCU) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(dioDFile)" -MT"$(dioOFile)" -c -o "$(dioOFile)" "$(dioCFile)"
	
	@echo "Generate Include files for main"
	@avr-gcc -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=$(MCU) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(mainDFile)" -MT"$(mainOFile)" -c -o "$(mainOFile)" "$(mainCFile)"

#flags 
# -Wl [Mandatory]: Passing various linker options to control the linking process
linker: build
	@avr-gcc -Wl,-Map,$(mapFile) -mmcu=atmega32 -o "$(elfFile)"  $(rtosOFile)  $(timer1OFile)  $(dioOFile)  $(mainOFile)   

Listing: linker
	@avr-objdump -h -S $(elfFile)  >"$(lssFile)"

flashImage: Listing
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex $(elfFile)  "$(hexFile)"
