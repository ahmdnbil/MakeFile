include buildProcess.mk
	
defalut: flashImage	
clean:
	@rm -r Debug


.PHONY: folder
folder:
	@mkdir -p $(PATHS)

build: folder 
	@echo "Generate Include files for main"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)   -o "$(mainOFile)" -c  "$(mainCFile)"

	@echo "Generate Include files for TIMER1"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)   -o "$(timer1OFile)" -c "$(timer1CFile)"

	@echo "Generate Include files for RTOS"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)  -o "$(rtosOFile)" -c "$(rtosCFile)"
	
	
	@echo "Generate Include files for DIO"
	@$(CC) -Os -funsigned-char -mmcu=$(DEVICE) -DF_CPU=$(CPU_CLK)   -o "$(dioOFile)" -c "$(dioCFile)"
	

#flags 
# -Wl [Mandatory]: Passing various linker options to control the linking process
linker: build
	@$(CC) -mmcu=$(DEVICE) -o "$(elfFile)"  $(rtosOFile)  $(timer1OFile)  $(dioOFile)  $(mainOFile)   

Listing: linker
	@avr-objdump -h -S $(elfFile)  >"$(lssFile)"

flashImage: Listing
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex $(elfFile)  "$(hexFile)"
