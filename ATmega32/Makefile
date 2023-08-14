include makeFolders.mk
include buildProcess.mk
	
defalut: flashImage

clean:
	@rm -r Debug

folder:
	@$(foreach word,$(folders),mkdir -p $(word))

build: folder 
	@echo "Generate Include files for RTOS"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)  -o "$(rtosOFile)" -c "$(rtosCFile)"
	
	@echo "Generate Include files for TIMER1"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)  -o "$(timer1OFile)" -c "$(timer1CFile)"
	
	@echo "Generate Include files for DIO"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)  -o "$(dioOFile)" -c "$(dioCFile)"
	
	@echo "Generate Include files for main"
	@avr-gcc -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)  -o "$(mainOFile)" -c "$(mainCFile)"

linker: build
	@avr-gcc  -mmcu=$(DEVICE) -o "$(elfFile)"  $(rtosOFile)  $(timer1OFile)  $(dioOFile)  $(mainOFile)   

Listing: linker
	@avr-objdump -h -S $(elfFile)  >"$(lssFile)"

flashImage: Listing
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex $(elfFile)  "$(hexFile)"
