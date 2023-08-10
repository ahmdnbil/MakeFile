include makeFolders.mk
include buildProcess.mk
	
defalut: flashImage

clean:
	@rm -r Debug

folder:
	@$(foreach word,$(folders),mkdir -p $(word))

build: folder 
	@echo "Generate Include files for RTOS"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(rtosDFile)" -MT"$(rtosOFile)" -c -o "$(rtosOFile)" "$(rtosCFile)"
	
	@echo "Generate Include files for TIMER1"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(timer1DFile)" -MT"$(timer1OFile)" -c -o "$(timer1OFile)" "$(timer1CFile)"
	
	@echo "Generate Include files for DIO"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(dioDFile)" -MT"$(dioOFile)" -c -o "$(dioOFile)" "$(dioCFile)"
	
	@echo "Generate Include files for main"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK) -MMD -MP -MF"$(mainDFile)" -MT"$(mainOFile)" -c -o "$(mainOFile)" "$(mainCFile)"

#flags 
# -Wl [Mandatory]: Passing various linker options to control the linking process
linker: build
	@avr-gcc -Wl,-Map,$(mapFile) -mmcu=$(DEVICE) -o "$(elfFile)"  $(rtosOFile)  $(timer1OFile)  $(dioOFile)  $(mainOFile)   

Listing: linker
	@avr-objdump -h -S $(elfFile)  >"$(lssFile)"

flashImage: Listing
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex $(elfFile)  "$(hexFile)"
